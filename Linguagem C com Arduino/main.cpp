#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

#define porta 4

const char* ssid = "";
const char* password = "";


const char *bot_token = "";

const char *mensagem = "/abrir";
const String userId[] = {}; // ID de usuário da pessoa que deseja monitorar

void setup()
{
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.println("Conectando a rede WiFi...");
  }

  Serial.println("Conectado à rede WiFi");
  pinMode(porta, OUTPUT);
  digitalWrite(porta, HIGH);
}

void loop()
{
  int update_id;
  HTTPClient http;
  int acesso = -1;
  String url = "https://api.telegram.org/bot" + String(bot_token) + "/getUpdates?offset=-1&limit=1&timeout=0&allowed_updates=[\"message\"]";

  http.begin(url);
  int httpCode = http.GET();

  String id;
  if (httpCode > 0)
  {
    String payload = http.getString();

    int idIndex = payload.indexOf("\"id\":");
    Serial.println(idIndex);
    int commaIndex = payload.indexOf(",", idIndex);
    id = payload.substring(idIndex + 5, commaIndex);
    int temp = payload.indexOf("\"update_id\":");
    Serial.println(temp);
    int temp_2 = payload.indexOf(",", temp);
    update_id = payload.substring(temp + 12, temp_2).toInt();
    Serial.println(update_id);

    int t1 = payload.indexOf("\"username\":");
    int t2 = payload.indexOf("\",", t1);
    String usuario = payload.substring(t1 + 12, t2);

    for (int i = 0; i < (sizeof(userId) / sizeof(userId[0])); i++)
    {
      if (id == userId[i])
      {
        int textIndex = payload.indexOf("\"text\":\"");
        int textEndIndex = payload.indexOf("\",", textIndex + 8);
        String message = payload.substring(textIndex + 8, textEndIndex);

        if (message == mensagem)
        {
          acesso = i;
          url = "https://api.telegram.org/bot" + String(bot_token) + "/getUpdates?offset=" + String(update_id + 1);
          http.begin(url);
          http.GET();
          http.end();
          url = "https://api.telegram.org/bot" + String(bot_token) + "/sendMessage?chat_id=" + userId[0] + "&text=O usuário acessou a porta: " + id;
          http.begin(url);
          http.GET();
          http.end();
        }
        if (message == "/on")
        {
          String url = "https://api.telegram.org/bot" + String(bot_token) + "/sendMessage?chat_id=" + userId[i] + "&text=Estou online!";
          Serial.println(url);
          http.begin(url);
          int httpCode = http.GET();

          if (httpCode > 0)
          {
            String response = http.getString();
            Serial.println(httpCode);
            Serial.println(response);
          }
          else
          {
            Serial.println("Erro ao enviar mensagem!");
          }
          url = "https://api.telegram.org/bot" + String(bot_token) + "/getUpdates?offset=" + String(update_id + 1);
          http.begin(url);
          http.GET();
          http.end();
        }
      }
    }
    http.end();
  }
  else
  {
    Serial.println("Falha ao obter atualizações do Telegram");
  }
  http.end();
  Serial.println(acesso);
  if (acesso != -1)
  {
    String url = "https://api.telegram.org/bot" + String(bot_token) + "/sendMessage?chat_id=" + userId[acesso] + "&text=porta aberta!";
    digitalWrite(porta, LOW);
    delay(300);
    digitalWrite(porta, HIGH);
    Serial.println(url);
    http.begin(url);
    int httpCode = http.GET();

    if (httpCode > 0)
    {
      String response = http.getString();
      Serial.println(httpCode);
      Serial.println(response);
    }
    else
    {
      Serial.println("Erro ao enviar mensagem!");
    }
    http.end();
  }
}
