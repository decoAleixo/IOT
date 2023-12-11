// Definindo o pino do sensor de temperatura LM36
#define LM36_PIN A0

// Definindo os pinos para o motor, LED e buzina
#define MOTOR_PIN 8
#define LED_PIN 9
#define BUZZER_PIN 7

// Definindo as temperaturas de referência
#define TEMPERATURA_LIMITE_NORMAL 30
#define TEMPERATURA_LIMITE_EMERGENCIA 50

void setup() {
  // Configurando os pinos como saídas
  pinMode(MOTOR_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // Fazendo a leitura da temperatura
  int valorSensor = analogRead(LM36_PIN);
  float tensao = (valorSensor / 1024.0) * 5.0;  // Convertendo para tensão
  float temperatura = (tensao - 0.5) * 100.0;  // Convertendo para temperatura em graus Celsius

  // Verificando a temperatura e acionando o motor, LED e buzina conforme necessário
  if (temperatura >= TEMPERATURA_LIMITE_NORMAL) {
    // Acionando o motor de ventilador
    digitalWrite(MOTOR_PIN, HIGH);
  } else {
    // Desligando o motor de ventilador
    digitalWrite(MOTOR_PIN, LOW);
  }

  if (temperatura >= TEMPERATURA_LIMITE_EMERGENCIA) {
    // Acionando o LED vermelho
    digitalWrite(LED_PIN, HIGH);
    
    // Acionando a buzina
    tone(BUZZER_PIN, 1000);  // 1000 Hz
  } else {
    // Desligando o LED vermelho
    digitalWrite(LED_PIN, LOW);
    
    // Desligando a buzina
    noTone(BUZZER_PIN);
  }

  // Aguardando um intervalo antes da próxima leitura
  delay(1000);  // Aguarda 1 segundo
}