// HC-SR04 핀 설정
const int trigPin = 6;
const int echoPin = 7;

// 거리 계산을 위한 변수
long duration;
float distance;

void setup() {
  // 핀 모드 설정
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // 시리얼 통신 시작
  Serial.begin(9600);
}

void loop() {
  // Trig 핀에 10μs 펄스 신호를 보냄
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Echo 핀의 신호 지속 시간 측정
  duration = pulseIn(echoPin, HIGH);

  // 초음파의 속도를 이용해 거리 계산 (단위: cm)
  distance = duration * 0.034 / 2;

  // 거리 출력
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // 100ms 대기
  delay(100);
}