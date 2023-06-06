//Código para controlar dos motorreductores con puente H por medio de Joystick.
//Código por Sebastián Leonardo Córdoba Cuadros.

const int in1 = 2;
const int in2 = 3;
const int in3 = 4;
const int in4 = 5;
const int SW = 6;
const int RX = A2;
const int RY = A3;

int X = 0;
int Y = 0;

void setup() {
  pinMode(SW, INPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  Serial.begin(9600);
  Serial.println("\t");
  Serial.print("X");
  Serial.print("\t");
  Serial.print("Y");
  Serial.println("\t");
}

void loop() {
  int valorSW = digitalRead(SW);
  int valorX = analogRead(RX);
  int valorY = analogRead(RY);

  //  variable nueva = map(variable original, minímo original, máximo original, nuevo mínimo/máximo, nuevo máximo/mínimo)
  X = map(valorX, 0, 1023, 0, 179);
  Y = map(valorY, 0, 1023, 179, 0);
  if (valorSW == 1) {
    //Cuando se presiona el pulsador, la ejecución de movimiento en los motores se detiene.
    //Tras una serie de pruebas, se determinó que, para evitar movimientos indeseados cuando. el Joystick no está en movimiento, se debe dar un rango de datos entre 85 y 95 y no se debe dejar solo en 90.
    if (X >= 85 and X <= 95) {
      //    ALTO
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
    }
    else if (X < 85) {
      //    Sentido Antihorario
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
    }
    else if (X > 95) {
      //    Sentido Horario
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
    }

    if (Y >= 85 and Y <= 95) {
      //    ALTO
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
    }
    else if (Y < 85) {
      //    Sentido Antihorario
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
    }
    else if (Y > 95) {
      //    Sentido Horario
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
    }
  }
  else if (valorSW == 0) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }


  Serial.print(X);
  Serial.print("\t");
  Serial.print(Y);
  Serial.println("\t");

  delay(20);
}
