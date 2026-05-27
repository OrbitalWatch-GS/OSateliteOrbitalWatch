#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

const int PIN_TRIG = 12;
const int PIN_ECHO = 11;
const int LED_VERDE = 2;
const int LED_AMARELO = 3;
const int LED_VERMELHO = 4;
const int PIN_BUZZER = 5;
const int PIN_BOTAO = 7;

long duracao;
float distanciaCm;
bool manobraExecutada = false;

void setup() {
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(PIN_BUZZER, OUTPUT);
  pinMode(PIN_BOTAO, INPUT);
  
  lcd.begin(16, 2);
  
  lcd.setCursor(0, 0);
  lcd.print("OrbitalWatch v1");
  lcd.setCursor(0, 1);
  lcd.print("Sistemas: ONLINE");
  delay(1500);
  lcd.clear();
}

void loop() {
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);
  
  duracao = pulseIn(PIN_ECHO, HIGH);
  
  distanciaCm = duracao * 0.034 / 2;
  
  if (digitalRead(PIN_BOTAO) == HIGH && distanciaCm < 50) {
    manobraExecutada = true;
  }

  if (manobraExecutada) {
    noTone(PIN_BUZZER);
    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(LED_AMARELO, HIGH);
    digitalWrite(LED_VERMELHO, HIGH);
    
    lcd.setCursor(0, 0);
    lcd.print("MANOBRA MANUAL  ");
    lcd.setCursor(0, 1);
    lcd.print("EXECUTADA: OK!  ");
    
    delay(3000);
    manobraExecutada = false;
    lcd.clear();
  } 
  else if (distanciaCm > 150) {
    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_VERMELHO, LOW);
    noTone(PIN_BUZZER);
    
    lcd.setCursor(0, 0);
    lcd.print("STATUS: SEGURO  ");
    lcd.setCursor(0, 1);
    lcd.print("Orbita Limpa    ");
  } 
  else if (distanciaCm >= 50 && distanciaCm <= 150) {
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AMARELO, HIGH);
    digitalWrite(LED_VERMELHO, LOW);
    tone(PIN_BUZZER, 200);
    
    lcd.setCursor(0, 0);
    lcd.print("ALERTA: DETRITO ");
    lcd.setCursor(0, 1);
    lcd.print("Prox: ");
    lcd.print(distanciaCm, 1);
    lcd.print("cm   ");
  } 
  else if (distanciaCm < 50) {
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_VERMELHO, HIGH);
    tone(PIN_BUZZER, 800);
    
    lcd.setCursor(0, 0);
    lcd.print("PERIGO: COLISAO ");
    lcd.setCursor(0, 1);
    lcd.print("APERTE P/ DESVIO");
  }

  delay(100);
}
