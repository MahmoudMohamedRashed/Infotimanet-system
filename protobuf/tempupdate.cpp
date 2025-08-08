#include <iostream>
#include <chrono>
#include <thread>
#include "mqtt/async_client.h"
#include "weather.pb.h"

const std::string SERVER_ADDRESS = "tcp://localhost:1883";
const std::string CLIENT_ID = "temp_cpp_client";
const std::string REQ_TOPIC = "temp/request";
const std::string RES_TOPIC = "temp/response";

class callback : public virtual mqtt::callback {
public:
    void message_arrived(mqtt::const_message_ptr msg) override {
        weather::TemperatureResponse response;
        if (response.ParseFromString(msg->get_payload())) {
            std::cout << "Temperature: " << response.temperature() << "°C\n";
        } else {
            std::cerr << "Failed to parse protobuf response\n";
        }
    }
};

void requestTemperatureOnce() {
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    mqtt::async_client client(SERVER_ADDRESS, CLIENT_ID);
    callback cb;
    client.set_callback(cb);

    mqtt::connect_options connOpts;
    client.connect(connOpts)->wait();
    client.start_consuming();
    client.subscribe(RES_TOPIC, 1)->wait();

    mqtt::message_ptr pubmsg = mqtt::make_message(REQ_TOPIC, "");
    pubmsg->set_qos(1);
    client.publish(pubmsg)->wait();

    client.disconnect()->wait();
    google::protobuf::ShutdownProtobufLibrary();
}

int main() {
    while(1)requestTemperatureOnce();  
    return 0;
}
