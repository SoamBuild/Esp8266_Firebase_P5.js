# Historia

Este repositorio que nace de un desafio. El desafio era almacenar datos en firebase y luego recuperarlos desde p5.js, en intentos previos lo habia logrado pero solo con la placa Particle Photon, que es un excelente controlador pero es un poco caro, es por esto que en este segundo intento lo hago un esp8266 y para no extenderme en como graficar los datos Ocupe Chart.js . para generar algo de datos ocupe un sensor de temperatura y humedad, pero este puede ser reemplazado por cualquier otro sensor.

## Materiales

1.  Esp8266
    
2.  Dht11 o cualquier otro sensor
    
3.  Jumpers
    
4.  Cuenta de firebase
    

## Electronica

En mi caso la placa que tenia a mano era un nodeMcu amica, y esta placa funciona bien pero al ocupar los pines en arduino, esto se vuelve un poco mas dificil de igual manera si tienes un nodeMcu amica deje una imagen con la conexion del sensor. Toda placa esp8266 deberia funcionar.

## .ino y libreria

En este punto estuve bastante detenido. El primer problema fue encontrar los pines de la placa mediante arduino. Y segundo conectar la placa a firebase, ya que todos los tutoriales que encontre ocupaban una libreria que funcionaba en paralelo con otra libreria.

El problema primero fue que la ultima version de la libreria no era compatible por lo cual no podian trabajar en paralelo. Luego que instale una libreria mas vieja y logre compilar el codigo, por lo tanto ya estaba listo para visualizar mis datos en firebase, pero no. Mi placa no se conectaba a firebase, primero pense que podria ser algun error mio y revise, todo estaba en orden, luego de perder tiempo revisando, me di cuenta que a mucha gente le habia dejado de funcionar la libreria, la placa sencillamente no se conectaba con firebase.

Me puse a buscar otras librerias dentro de github y finalemnte encontre esta libreria [firebase esp8266]([https://github.com/mobizt/Firebase-ESP8266](https://github.com/mobizt/Firebase-ESP8266) , esta libreria si me funciono y logre mandar mis datos con el esp8266, otra ventaja de esta libreria es que funciona por si sola y no en paralelo como la que habia probado anteriormente. Y tambien la instalacion es sencilla ya que se instala del mismo ArduinoIDE

## Chart.js y P5.js

Ultimamente estoy ocupando mucho p5.js online editor ya que permite trabajar mas rapido, aca el primer problema fue averiguar como traer los datos desde firebase a la consola del editor. En mi primer intento con la placa Photon, me habia apoyado desde este [codigo ]([https://gist.github.com/jkuip/cb1e4e5b24b118407e8db19ff52304d7](https://gist.github.com/jkuip/cb1e4e5b24b118407e8db19ff52304d7), pero ahora no funcionaba averigue y se trataba de un error provocado por el editor online y encontre la solucion. Asi que este codigo deberia correr sin problemas en el editor online de p5.

Para graficar los valores que consulto en firebase, ocupe chart.js.

## Proximos pasos

1.  Aprender mas sobre las consultas a firebase
    
2.  Ordenar los codigos
    
3.  Documentar todo para el esp32
    
4.  Probar otras manera de ver los graficos por dia por hora, creo que esto depende de la consulta que haga en firebase
