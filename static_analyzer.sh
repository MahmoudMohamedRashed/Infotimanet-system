#!/bin/bash

PWD=$(pwd)
SOURCE_DIR=$(realpath "$PWD")

# Detect build directory type (debug, release, profile)
BUILD_DIR=""
for BUILD_TYPE in Debug Release Profile; do
    DETECTED_BUILD_DIR=$(find "$SOURCE_DIR/build" -type d -name "*Desktop_Qt_*-$BUILD_TYPE" 2>/dev/null | head -n 1)
    if [ -n "$DETECTED_BUILD_DIR" ]; then
        BUILD_DIR=$DETECTED_BUILD_DIR
        break
    fi
done

if [ -z "$BUILD_DIR" ]; then
    echo "Failed to detect a valid build directory (Debug/Release/Profile)" 1>&2
    exit 1
fi

COMPILE_DB="compile_commands.json"
COMPILE_DB_PATH="$BUILD_DIR/.qtc_clangd/$COMPILE_DB"

# Check if compile_commands.json exists
if [ ! -e "$COMPILE_DB_PATH" ]; then
    echo "Didn't find $COMPILE_DB"
    echo "You should install the bear package 'sudo apt install bear' and reopen QT Creator and rebuild again."
    exit 1
fi

# List all available modules excluding 'build'
AVAILABLE_MODULES=()
INDEX=0

echo "Available modules:"
while IFS= read -r module; do
    AVAILABLE_MODULES+=("$module")
    echo "$INDEX: $module"
    ((INDEX++))
done < <(find "$SOURCE_DIR" -maxdepth 1 -mindepth 1 -type d -not -name 'build' -exec basename {} \;)

# Detect root-level source files
ROOT_LEVEL_FILES=($(find "$SOURCE_DIR" -maxdepth 1 -type f \( -name '*.cpp' \)))
if [ ${#ROOT_LEVEL_FILES[@]} -gt 0 ]; then
    echo "$INDEX: Root-Level Source Files"
    ROOT_LEVEL_INDEX=$INDEXmahmoud@Lab:/media/mahmoud/A4F07335F0730D34/Qt_Brightskies/PROJECT/InfoScreen$ git pull origin main --rebase 
error: cannot pull with rebase: Your index contains uncommitted changes.
error: please commit or stash them.
    AVAILABLE_MODULES+=("Root-Level Source Files")  # Add to the list
    ((INDEX++))
fi

# Prompt user to select modules
echo "Enter the module numbers you want to analyze as a comma-separated list (e.g., 0,1,2), or type 'all' to analyze all modules:"
read -r MODULE_INPUT

while true; do
    if [ "$MODULE_INPUT" == "all" ]; then
        MODULES=("${AVAILABLE_MODULES[@]}")
        break
    else
        IFS=',' read -ra SELECTED_INDICES <<< "$MODULE_INPUT"
        MODULES=()
        INVALID_INPUT=false

        for INDEX in "${SELECTED_INDICES[@]}"; do
            if [[ $INDEX =~ ^[0-9]+$ ]] && [ "$INDEX" -lt "${#AVAILABLE_MODULES[@]}" ]; then
                MODULES+=("${AVAILABLE_MODULES[$INDEX]}")
            else
                echo "Warning: Invalid module index '$INDEX'. Please enter valid indices."
                INVALID_INPUT=true
                break
            fi
        done

        if ! $INVALID_INPUT; then
            break
        else
            echo "Please enter a valid input. Use 'all' or indices separated by commas."
            read -p "Enter module selection: " MODULE_INPUT
        fi
    fi
done

LINTER=clang-tidy 
CHECKS=$1

# Path to store the output
OUTPUT_DIR=$(realpath "$PWD/../results")
OUTPUT_FILE="$OUTPUT_DIR/static_analysis_output.txt"

# ✅ Ensure output directory exists
if [ -d "$OUTPUT_DIR" ]; then
    echo "Output directory '$OUTPUT_DIR' already exists."
else
    mkdir -p "$OUTPUT_DIR"
    echo "Created output directory '$OUTPUT_DIR'."
fi

# ✅ Ensure output file is cleared or created
if [ -f "$OUTPUT_FILE" ]; then
    > "$OUTPUT_FILE"
    echo "Cleared existing output file '$OUTPUT_FILE'."
else
    touch "$OUTPUT_FILE"
    echo "Created new output file '$OUTPUT_FILE'."
fi

# ✅ If no modules are selected, analyze all
if [ ${#MODULES[@]} -eq 0 ]; then
    MODULES=($(find "$SOURCE_DIR" -maxdepth 1 -mindepth 1 -type d -not -name 'build' -exec basename {} \;))
fi

echo "Running $LINTER on source files..."

# Analyze selected modules (including root-level files)
for MODULE in "${MODULES[@]}"; do
    if [ "$MODULE" == "Root-Level Source Files" ]; then
        FILES=("${ROOT_LEVEL_FILES[@]}")
    else
        MODULE_PATH="$SOURCE_DIR/$MODULE"
        FILES=($(find "$MODULE_PATH" -name '*.cpp'))
    fi

    echo -e "**********************  Analysis Results for Module: $MODULE " >> "$OUTPUT_FILE"
    echo -e "----------------------------------------------------\n" >> "$OUTPUT_FILE"

    FILE_COUNT=${#FILES[@]}
    echo "Number of .cpp files in module '$MODULE': $FILE_COUNT"

    if [ $FILE_COUNT -eq 0 ]; then
        echo "_____ No source files found in module '$MODULE'." >> "$OUTPUT_FILE"
        continue
    fi

    for FILE in "${FILES[@]}"; do
        OUTPUT=$($LINTER $CHECKS -p "$COMPILE_DB_PATH" \
        --header-filter="$SOURCE_DIR/.*" \
        "$FILE" 2>&1)
        OUTPUT_FILTERED=$(echo "$OUTPUT" | grep -vE "Suppressed|warnings generated|Use -header-filter=.*|Use -system-headers")

        if [ -n "$OUTPUT_FILTERED" ]; then
            echo "File: $(basename "$FILE")" >> "$OUTPUT_FILE"
            echo -e "-----------------------\n" >> "$OUTPUT_FILE"
            echo "$OUTPUT_FILTERED" >> "$OUTPUT_FILE"
        fi
    done

    echo -e "**********************  Completed analysis for Module: $MODULE " >> "$OUTPUT_FILE"
    echo -e "=====================================================================================================\n" >> "$OUTPUT_FILE"
done

echo "Analysis complete. Results are stored in $OUTPUT_FILE"
