void sensorTest()
{
	Serial.print(analogRead(A1));
	Serial.print("\t");
	Serial.print(analogRead(A2));
	Serial.print("\t");
	Serial.println(analogRead(A4));
}
