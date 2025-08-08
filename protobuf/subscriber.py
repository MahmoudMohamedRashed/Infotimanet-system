import paho.mqtt.client as mqtt
import requests
import time
import weather_pb2
import geocoder

BROKER = "localhost"
REQ_TOPIC = "temp/request"
RES_TOPIC = "temp/response"

def get_temperature():
    # Get latitude and longitude based on IP
    g = geocoder.ip('me')
    if not g.latlng:
        print("Failed to determine location.")
        return None
    lat, lon = g.latlng

    # Use OpenWeatherMap API
    api_key = "35e68cb729654b06a36e89bfeb38f2fd"
    url = f"https://api.openweathermap.org/data/2.5/weather?lat={lat}&lon={lon}&appid={api_key}&units=metric"

    try:
        r = requests.get(url)
        r.raise_for_status()  # Raise exception if not 200
        data = r.json()
        temp = data.get("main", {}).get("temp")
        if temp is None:
            print("Temperature data missing in response.")
        return temp
    except Exception as e:
        print(f"Error fetching weather data: {e}")
        return None

def on_message(client, userdata, msg):
    print("Request received")
    temp = get_temperature()
    if temp is not None:
        print(f"Temperature: {temp}°C")
        response = weather_pb2.TemperatureResponse()
        response.temperature = temp
        client.publish(RES_TOPIC, response.SerializeToString())
    else:
        print("Failed to get temperature. No response published.")

client = mqtt.Client()
client.on_message = on_message
client.connect(BROKER)
client.subscribe(REQ_TOPIC)
client.loop_forever()

