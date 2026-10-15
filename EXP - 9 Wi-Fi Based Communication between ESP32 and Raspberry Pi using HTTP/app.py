from flask import Flask, request

app = Flask(__name__)

@app.route("/")
def home():
    return "IoT Server is Running"

@app.route("/data")
def receive_data():

    temperature = request.args.get("temperature")
    humidity = request.args.get("humidity")

    print("--------------------------------")
    print("Data received from ESP32")
    print("Temperature :", temperature, "°C")
    print("Humidity    :", humidity, "%")
    print("--------------------------------")

    return "Sensor data received successfully"


if __name__ == "__main__":
    app.run(host="0.0.0.0",port=5000)
