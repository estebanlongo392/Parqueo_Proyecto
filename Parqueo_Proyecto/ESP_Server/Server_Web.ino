#include <Wire.h>
#include <WiFi.h>
#include <WebServer.h>

// Configuración de WiFi
const char* ssid = "iPhone de Rudy";  // Cambia esto por tu SSID
const char* password = "tato2004"; // Cambia esto por tu contraseña

// Crear servidor web en el puerto 80
WebServer server(80);

// Dirección I2C del ESP32 como esclavo
#define ESP32_ADDRESS 0x10

// Variables de estado para cada parqueo
String estadoParqueo[8] = {
  "<span class='status libre'>Libre</span>", "<span class='status libre'>Libre</span>",
  "<span class='status libre'>Libre</span>", "<span class='status libre'>Libre</span>",
  "<span class='status libre'>Libre</span>", "<span class='status libre'>Libre</span>",
  "<span class='status libre'>Libre</span>", "<span class='status libre'>Libre</span>"
};

// Función para configurar el ESP32 y el servidor
void setup() {
  // Configurar la comunicación serie
  Serial.begin(115200);

  // Conectar a WiFi
  WiFi.begin(ssid, password);
  Serial.print("Conectando a WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Conectado! IP: ");
  Serial.println(WiFi.localIP());

  // Configurar el ESP32 como esclavo en el bus I2C
  Wire.begin(ESP32_ADDRESS);
  Wire.onReceive(receiveEvent); // Función de callback para recepción de datos I2C

  // Configurar las rutas del servidor
  server.on("/", conexion);
  server.on("/estado", handleEstado);

  // Iniciar el servidor
  server.begin();
  Serial.println("Servidor iniciado.");
}

// Función principal
void loop() {
  // Manejar las peticiones del servidor
  server.handleClient();
}

// Función de callback para recibir datos por I2C
void receiveEvent(int bytes) {
  while (Wire.available()) {
    char receivedChar = Wire.read(); // Leer el carácter recibido

    // Imprimir el carácter recibido en la terminal serie para verificación
    Serial.print("Carácter recibido por I2C: ");
    Serial.println(receivedChar);

    // Actualizar el estado del parqueo según el carácter recibido
    switch (receivedChar) {
      case 'a': estadoParqueo[0] = "<span class='status ocupado'>Ocupado</span>"; break;
      case 'A': estadoParqueo[0] = "<span class='status libre'>Libre</span>"; break;
      case 'b': estadoParqueo[1] = "<span class='status ocupado'>Ocupado</span>"; break;
      case 'B': estadoParqueo[1] = "<span class='status libre'>Libre</span>"; break;
      case 'c': estadoParqueo[2] = "<span class='status ocupado'>Ocupado</span>"; break;
      case 'C': estadoParqueo[2] = "<span class='status libre'>Libre</span>"; break;
      case 'd': estadoParqueo[3] = "<span class='status ocupado'>Ocupado</span>"; break;
      case 'D': estadoParqueo[3] = "<span class='status libre'>Libre</span>"; break;
      case 'e': estadoParqueo[4] = "<span class='status ocupado'>Ocupado</span>"; break;
      case 'E': estadoParqueo[4] = "<span class='status libre'>Libre</span>"; break;
      case 'f': estadoParqueo[5] = "<span class='status ocupado'>Ocupado</span>"; break;
      case 'F': estadoParqueo[5] = "<span class='status libre'>Libre</span>"; break;
      case 'g': estadoParqueo[6] = "<span class='status ocupado'>Ocupado</span>"; break;
      case 'G': estadoParqueo[6] = "<span class='status libre'>Libre</span>"; break;
      case 'h': estadoParqueo[7] = "<span class='status ocupado'>Ocupado</span>"; break;
      case 'H': estadoParqueo[7] = "<span class='status libre'>Libre</span>"; break;
      default: 
        Serial.println("Carácter desconocido"); // Manejo de caracteres no especificados
        break;
    }
  }
}

// Función para servir la página principal
void conexion() {
  String text = "<!DOCTYPE html> <html>\n";
  text += "<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  text += "<title>SISTEMA DE PARQUEOS</title>\n";
  text += "<style>";

  // Estilos CSS
  text += "body { background-image: url('https://i.postimg.cc/1t5H1syL/park.jpg'); background-size: cover; background-repeat: no-repeat;";
  text += "background-position: center; font-family: Arial, sans-serif; color: white; text-align: center; margin: 0; padding: 0;}";
  text += ".status { font-weight: bold; padding: 5px; border-radius: 5px; color: white; }";
  text += ".libre { background-color: green; }";
  text += ".ocupado { background-color: red; }";

  // Script de actualización AJAX
  text += "</style>";
  text += "<script>\n";
  text += "function actualizarEstado() {\n";
  text += "  var xhr = new XMLHttpRequest();\n";
  text += "  xhr.onreadystatechange = function() {\n";
  text += "    if (xhr.readyState == 4 && xhr.status == 200) {\n";
  text += "      document.getElementById('parqueo1').innerHTML = xhr.responseText.split(',')[0];\n";
  text += "      document.getElementById('parqueo2').innerHTML = xhr.responseText.split(',')[1];\n";
  text += "      document.getElementById('parqueo3').innerHTML = xhr.responseText.split(',')[2];\n";
  text += "      document.getElementById('parqueo4').innerHTML = xhr.responseText.split(',')[3];\n";
  text += "      document.getElementById('parqueo5').innerHTML = xhr.responseText.split(',')[4];\n";
  text += "      document.getElementById('parqueo6').innerHTML = xhr.responseText.split(',')[5];\n";
  text += "      document.getElementById('parqueo7').innerHTML = xhr.responseText.split(',')[6];\n";
  text += "      document.getElementById('parqueo8').innerHTML = xhr.responseText.split(',')[7];\n";
  text += "    }\n";
  text += "  };\n";
  text += "  xhr.open('GET', '/estado', true);\n";
  text += "  xhr.send();\n";
  text += "}\n";
  text += "setInterval(actualizarEstado, 1000); // Actualizar cada 1 segundo\n";
  text += "</script>\n";
  text += "</head>\n";
  text += "<body>\n";
  text += "<h1 style=\"color: #5e9ca0;\">Rodolfo's SmartPark SA</h1>\n";
  text += "<h1 style=\"color: #5e9ca0;\">Innovacion y Comodidad en Cada Espacio</h1>\n";
  for (int i = 1; i <= 8; i++) {
    text += "<h3>PARQUEO " + String(i) + ": <span id='parqueo" + String(i) + "' class=\"status\">" + estadoParqueo[i-1] + "</span></h3>";
  }
  text += "</body></html>";

  server.send(200, "text/html", text);
}

// Función para manejar la solicitud AJAX de /estado
void handleEstado() {
  String estados = "";
  for (int i = 0; i < 8; i++) {
    estados += estadoParqueo[i];
    if (i < 7) estados += ",";
  }
  server.send(200, "text/plain", estados);
}
