let count = 0 //Contador de datos que llegan

//###Setup Firebase
let config = {
  apiKey: "YOURAPIKEY",
  authDomain: "YOURAUTHDOMAIN",
  databaseURL: "YOURDATABASEURL",
  storageBucket: "YOURSTORAGEBUCKET",
  messagingSenderId: "YOURMESSAGINGSENDERID"
  }
//###Firebase configuracion y inicio
firebase.initializeApp(config);
var database = firebase.database();
//###Referencia de consulta
database.ref('DATAFROMESP8266').limitToLast(1).on('child_added', function(snapshot)
{
  var data = snapshot.val()//data es igual a snapshot.val()
  count++//+1 si llega un dato
  addData(hum, count, data.humedad)//Actualizo grafico (chart,label,data)
  addData(temp, count, data.Temperatura)//Actualizo grafico (chart,label,data)
  console.log("Temperatura DB = " + data.Temperatura)//Imprimo Temperatura
  console.log("Humedad DB = " + data.humedad)//Imprimo Humedad
})
//###Funcion actualizar graficos
function addData(chart, label, data) {
  chart.data.labels.push(label);
  chart.data.datasets.forEach((dataset) => {
    dataset.data.push(data);
  });
  chart.update();
}
var ctx = document.getElementById('graficoHumedad').getContext('2d');//Desde html grafico humedad
var hum = new Chart(ctx, {
  // Tipo de grafico a crear
  type: 'line',
  // parametros para el dataset
  data: {
    labels: [], //Etiquetas las actualizo desde funcion
    datasets: [{
      label: 'Humedad', //Etiqueta de titulo graficoHumedad
      backgroundColor: 'rgb(255, 99, 132)',//Color de relleno
      borderColor: 'rgb(255, 0, 0)',//Color de borde o linea
      data: []//Etiquetas lo actualizo desde funcion
    }]
  },
  // Configuraciones adicionales
  options: {}
});
var ctx = document.getElementById('graficoTemperatura').getContext('2d');//Desde html grafico Temperatura
var temp = new Chart(ctx, {
  // Tipo de grafico a crear
  type: 'line',
  // parametros para el dataset
  data: {
    labels: [],//Etiquetas las actualizo desde funcion
    datasets: [{
      label: 'Temperatura',
      backgroundColor: 'rgb(0, 255, 132)',//Color de relleno
      borderColor: 'rgb(0, 255, 0)',//Color de borde o linea
      data: []//data lo actualizo desde funcion
    }]
  },
  // Configuraciones adicionales 
  options: {}
});
