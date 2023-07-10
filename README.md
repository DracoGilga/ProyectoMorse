# Proyecto Morse

Este proyecto utiliza Arduino para implementar un código que permite parpadear un LED en código Morse. Para que funcione correctamente, es necesario configurar las credenciales de la red WiFi en un archivo separado llamado "CredencialesWifi.h" ubicado en la carpeta "CodigoArduino/ArduinoMorse". A continuación, se explica cómo configurar este archivo:

## Configuración de las credenciales WiFi

1. En la carpeta **[\`CodigoArduino/ArduinoMorse`](/CodigoArduino/ArduinoMorse)** , crea un nuevo archivo llamado "CredencialesWifi.cpp".

2. Abre el archivo "CredencialesWifi.cpp" y define las siguientes constantes:

```cpp
const char* ssid = "nombre_de_red";
const char* password = "contraseña_de_red";
````

Guarda y cierra el archivo.
Asegúrate de que el archivo "CredencialesWifi.h"  no se comparta públicamente y que las credenciales de tu red WiFi sean mantenidas de manera segura.

## Instrucciones adicionales

Puedes copiar y pegar este código Markdown en tu archivo README.md y adaptarlo según tus necesidades. Recuerda guardar los cambios en el archivo después de realizar las modificaciones.
