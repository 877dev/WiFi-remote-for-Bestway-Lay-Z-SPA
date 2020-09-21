void MQTTcallback(char* topic, byte* payload, unsigned int length) {  //877dev

  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  // Process message that comes in on the .../command topic
  if (String(topic).equals(String(base_mqtt_topic) + "/command"))
  {
    uint32_t cmd = strtol((const char *) &payload[0], NULL, 16);
    commandAction(cmd);
  }

} // End of void MQTTcallback
