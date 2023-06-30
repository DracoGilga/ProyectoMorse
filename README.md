# Proyecto Morse

Este proyecto utiliza Arduino para implementar un c�digo que permite parpadear un LED en c�digo Morse. Para que funcione correctamente, es necesario configurar las credenciales de la red WiFi en un archivo separado llamado "CredencialesWifi.h" ubicado en la carpeta "CodigoArduino/ArduinoMorse". A continuaci�n, se explica c�mo configurar este archivo:

## Configuraci�n de las credenciales WiFi

1. En la carpeta "CodigoArduino/ArduinoMorse", crea un nuevo archivo llamado "CredencialesWifi.h".

2. Abre el archivo "CredencialesWifi.h" y define las siguientes constantes:

```cpp
const char* ssid = "nombre_de_red";
const char* password = "contrase�a_de_red";

Guarda y cierra el archivo.
Aseg�rate de que el archivo "CredencialesWifi.h" no se comparta p�blicamente y que las credenciales de tu red WiFi sean mantenidas de manera segura.

# Instrucciones adicionales
...

Puedes copiar y pegar este c�digo Markdown en tu archivo README.md y adaptarlo seg�n tus necesidades. Recuerda guardar los cambios en el archivo despu�s de realizar las modificaciones.
