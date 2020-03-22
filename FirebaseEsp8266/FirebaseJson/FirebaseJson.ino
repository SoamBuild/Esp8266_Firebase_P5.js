//#1 _ Librerias
#include "FirebaseESP8266.h" //Libreria de firebase para esp8266 placa usada (Nodemcu Amica)
#include <ESP8266WiFi.h> // libreria para Wifi
#include "DHT.h" // Sensor Utilizado dht11 Keystudio
//#2 _ Configurar Sensor
#define DHTPIN 5 //Pin en la placa es D1
#define DHTTYPE DHT11 //DHT Modelo 11
DHT dht(DHTPIN, DHTTYPE); // Pin/Modelo
//#3 _ Configurar Firebase y Wifi
FirebaseJson Data;//Json a Firebase
#define FIREBASE_HOST "https://xxxxxxxxxx.firebaseio.com"
#define FIREBASE_AUTH "xxxxxxxxxxxxTk3dXSRf5bKrlxtnDyh"
#define WIFI_SSID "Huno"
#define WIFI_PASSWORD "20121804-7DxF"
//#4 _ Definir un objeto para enviar y recibir datos
FirebaseData firebaseData;
void setup()
{
  Serial.begin(115200); // Monitor Serial
  //#5 _ Conectandose a Internet
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);//Conectando a red Wifi Nombre/Contraseña
  Serial.print("Connecting to Wi-Fi");//Conectando a Wifi...
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());//Print Local ip de esp8266
  Serial.println();
  //#6 _ Iniciar Firebase
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);//Conectando con firebase url/key
  Firebase.reconnectWiFi(true);//Permitir reconectarse
  dht.begin();//Inicia Sensor
}
void loop()
{
  //#7 _ Crear variables obtener datos y check sensor
  float h = dht.readHumidity(); //Leer humedad desde sensor
  float t = dht.readTemperature();//Leer temperatura en grados celsius
  if (isnan(h) || isnan(t)) //Check si una lectura falla.
  {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  Serial.println("Temperatura : " + String(t) + "°"); //Imprime temperatura
  Serial.println("Humedad : " + String(h) + "%"); //Imprime Humedad
  delay(4000);//Espera 4 segundos
   //#8 _ Enviando datos
  Serial.println("Enviando Datos...");//Debug print
  Data.add("humedad", String(h)).add("Temperatura", String(t));//Agrega los datos al json que mandaremos
  //#8.1
  //Enviar los datos de manera simple
  //Firebase.pushJSON(firebaseData, " / DATAFROMESP8266", Data);
  //#8.2
  //Enviar los datos manera "avanzada"

  if (Firebase.pushJSON(firebaseData, " / DATAFROMESP8266", Data)) {
    Serial.println(firebaseData.dataPath());
    Serial.println(firebaseData.pushName());
    Serial.println(firebaseData.dataPath() + " / " + firebaseData.pushName());
  } else {
    Serial.println(firebaseData.errorReason());
  }
}
