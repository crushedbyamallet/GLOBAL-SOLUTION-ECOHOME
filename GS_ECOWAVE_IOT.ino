#include <ThingerESP32.h>

// definições do Thinger
#define USERNAME "crushedbyamallet"
#define DEVICE_ID "ecohome_device"
#define DEVICE_CREDENTIAL "xS0zfO!J7hWNlu8Q"
#define SSID "MSALETTE"
#define SSID_PASSWORD "m1r1c5j1"

ThingerESP32 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

// variáveis para simulação de consumo
float consumoTotal, consumoGeladeira, consumoAC, consumoTV, consumoMicroondas, consumoLuz;
int alertas;
String mensagemEconomia = "considere desligar dispositivos inativos para economizar energia.";
String projeto = "ECOHOME - sistema inteligente de monitoramento elétrico";

// função para gerar valores simulados de consumo em kW/h
float gerarConsumoSimulado(float minimo, float maximo) {
  return minimo + random(0, 1000) / 1000.0 * (maximo - minimo);
}

void setup() {
  Serial.begin(115200);
  thing.add_wifi(SSID, SSID_PASSWORD);
  
  // widgets no thinger.io
  thing["Projeto"] >> outputValue(projeto);  // widget 1 - título projeto
  thing["Consumo_Total"] >> outputValue(consumoTotal);  // widget 2 - gráfico consumo total
  thing["Consumo_Geladeira"] >> outputValue(consumoGeladeira);  // widget 3 - consumo geladeira
  thing["Consumo_AC"] >> outputValue(consumoAC);  // widget 4 - consumo ar-condicionado
  thing["Consumo_TV"] >> outputValue(consumoTV);  // widget 5 - consumo televisão
  thing["Consumo_Microondas"] >> outputValue(consumoMicroondas);  // widget 6 - consumo microondas
  thing["Consumo_Luz"] >> outputValue(consumoLuz);  // widget 7 - consumo lâmpadas
  thing["Alertas"] >> outputValue(alertas);  // widget 8 - alertas
  thing["Mensagem_Economia"] >> outputValue(mensagemEconomia);  // widget 9 - recomendações economia
}

void loop() {
  // atualizando valores simulados com base nas médias de consumo
  consumoGeladeira = gerarConsumoSimulado(0.5, 1.5);  // consumo da geladeira em kWh/dia (estimativa média)
  consumoAC = gerarConsumoSimulado(0.8, 2.5);  // consumo do ar-condicionado em kWh/dia (estimativa média)
  consumoTV = gerarConsumoSimulado(0.1, 0.5);  // consumo da TV em kWh/dia
  consumoMicroondas = gerarConsumoSimulado(0.3, 1.2);  // consumo do micro-ondas em kWh/dia
  consumoLuz = gerarConsumoSimulado(0.1, 1.0);  // consumo das lâmpadas em kWh/dia
  
  // calculando o consumo total como a soma dos consumos individuais
  consumoTotal = consumoGeladeira + consumoAC + consumoTV + consumoMicroondas + consumoLuz;
  
  // definindo alertas para consumo elevado
  alertas = (consumoTotal > 10.0) ? 1 : 0;  // alerta se o consumo total for maior que 10 kWh/dia
  
  // gerando mensagens de economia com base no consumo
  if (consumoTotal > 12.0) {
    mensagemEconomia = "consumo elevado! considere desligar dispositivos como ar-condicionado e TV.";
  } else if (consumoTotal > 8.0) {
    mensagemEconomia = "consumo moderado. verifique se a geladeira está em boa eficiência energética.";
  } else {
    mensagemEconomia = "bom consumo! continue monitorando o uso da energia.";
  }
  
  // enviando dados ao Thinger.io
  thing.handle();
  
  // atualizações a cada 10 segundos
  delay(10000);
}
