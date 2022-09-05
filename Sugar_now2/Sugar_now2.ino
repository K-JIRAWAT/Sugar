#include <Servo.h>
Servo myservo;
int sensor = 2; // ประกาศตัวแปรเครื่องหยอดเหรียญ
int led = 3; // ประกาศตัวแปร LED แสดงการทำงาน
int i = 0; // ประกาศตัวแปร นับจำนวนเหรียญ
int coin = 0; // ประกาศตัวแปร มูลค่าของเหรียญ ในที่นี้เป็น 10
int count = 0; // ประกาศตัวแปร นับการรับสัญญาณจากเครื่องหยอดเหรียญ 
boolean isCounter = false; // กำหนดให้ isCounter เป็นตัวแปรที่ไม่เป็นจริง


void setup() {
  myservo.attach(9); 
  pinMode(sensor, INPUT); 
  pinMode(led, OUTPUT); // กำหนดให้ตัวแปร led เป็นการส่งออกสัญญาณ
  attachInterrupt(0, doCounter, FALLING); // ทำงานแบบ interrupt เบอร์ 0 ในนี้คือขา 2
  // เมื่อเกิดเหตุการณ์ แรงดันที่ขา 2 มีการเปลี่ยนแปลงจากสัญญาณสูงเป็นต่ำ ให้ทำในฟังก์ชั่น doCounter
  Serial.begin(9600);
  myservo.writeMicroseconds(1300);
}

void loop() {
  if (isCounter == true) { // เมื่อ isCounter เป็นจริงให้เข้าเงื่อนไขทำงานถัดไป 
    isCounter = false; // ตั้งให้ไม่เป็นจริงเหมือนเดิมเพื่อ set การทำงานใหม่
    if (count >= 1) { // เมื่อ count มีค่ามากกว่าหรือเท่ากับ 1 ให้ทำงาน
      i = i + 1; // นับเหรียญโดยเพิ่มทีละหนึ่ง
      Serial.print("จำนวนเหรียญ : ");
      Serial.println(i);
      coin = i * 10; // คำนวณค่าเหรียญในที่นี้คือ 10 สามารถเปลี่ยนได้
      Serial.println("น้ำตาล : 500g");
      Serial.print("จำนวนเงิน : ");
      Serial.print(coin);
      Serial.println(" บาท");
      delay(1000); // หน่วงเวลา 1 วินาที
      coin = 0; // set ค่าให้เป็นเท่าเดิมเพื่อรับการทำงานใหม่
      i = 0; // set ค่าให้เป็นเท่าเดิมเพื่อรับการทำงานใหม่
      digitalWrite (led, HIGH);
      myservo.writeMicroseconds(1300);
//myservo.write(45); // สั่งให้ Servo หมุนไปองศาที่ 90
      Serial.println();
      Serial.print("ระบบทำงาน");
      Serial.println();
      Serial.print("LED ON");
      Serial.println();
      Serial.println();
      delay(5000); // หน่วงเวลา 5 วินาที
      Serial.print("เคลียร์เหรียญ / จำนวนเงิน");
      Serial.println();
      Serial.print("จำนวนเหรียญ : ");
      Serial.println(i);
      Serial.print("จำนวนเงิน : ");
      Serial.print(coin);
      Serial.println(" บาท");
      Serial.println();
      Serial.print("หยุดการทำงานของระบบ");
      Serial.println();
      digitalWrite (led, LOW);
     // myservo.write(90); // สั่งให้ Servo หมุนไปองศาที่ 0
      myservo.writeMicroseconds(2200);
      Serial.print("LED OFF");
      Serial.println();
      Serial.println();
      count = 0; // set ค่าให้เป็นเท่าเดิมเพื่อรับการทำงานใหม่
    }
  }
  
}

void doCounter() { // เมื่อเซ็นเซอร์ตรวจจับวัตถุ
  isCounter = true;
  count++; // ให้ตัวแปร count เพิ่มค่าบวก 1
  delay(1000); // หน่วงเวลา 1 วินาที
}
