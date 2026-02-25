String getHTML(float t, float u, float p, String weatherMsg) {
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta charset=\"UTF-8\">"; 
  ptr +="<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<title>Weather App</title>\n";
  ptr +="<style>body{font-family: Arial; text-align: center; background: #e0f7fa; margin: 0; padding: 20px;}\n";
  ptr +="h1 {color: #006064;} .box {background: #fff; border-radius: 10px; padding: 20px; margin: 15px auto; max-width: 300px; box-shadow: 0 5px 15px rgba(0,0,0,0.1); transition: 0.3s;}\n";
  ptr +=".box:active {transform: scale(0.98); background: #f0f0f0;}\n"; 
  ptr +=".val {font-size: 2.5em; font-weight: bold; color: #333;} .label {color: #666; font-size: 0.9em; text-decoration: none;}\n";
  ptr +="a {text-decoration: none; color: inherit;}\n"; 
  ptr +=".rain-box {background: #0277bd; color: white; padding: 15px; border-radius: 8px; margin: 20px auto; max-width: 300px; font-weight: bold;}\n";
  ptr +=".info {font-size: 0.8em; color: #888; margin-top: 30px;}\n";
  ptr +="</style><script>setInterval(function(){location.reload()}, 4000);</script>\n"; 
  ptr +="</head><body>\n";
  
  ptr +="<h1>🌤️ Live Weather Station</h1>\n";
  ptr +="<div class='rain-box'>" + weatherMsg + "</div>\n";
  
  ptr +="<a href='/history'><div class='box'><div class='label'>TEMPERATURE 🌡️</div><div class='val'>" + String(t, 1) + " &deg;C</div></div></a>\n";
  ptr +="<a href='/history'><div class='box'><div class='label'>HUMIDITY 💧</div><div class='val'>" + String(u, 0) + " %</div></div></a>\n";
  ptr +="<a href='/history'><div class='box'><div class='label'>PRESSURE ⏱️</div><div class='val'>" + String(p, 0) + " hPa</div></div></a>\n";
  
  ptr +="<div class='info'>Click cards for History</div>";
  ptr +="</body></html>\n";
  return ptr;
}

String getHistoryHTML(float* tempHistory, float* humHistory, float* presHistory, int count) {
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n";
  ptr +="<title>History</title>\n";
  ptr +="<style>body{font-family: Arial; text-align: center; background: #fff3e0; padding: 10px;}\n";
  ptr +="table {margin: 0 auto; border-collapse: collapse; width: 100%; max-width: 500px; background: white; font-size: 0.9em;}\n";
  ptr +="th, td {padding: 8px; border: 1px solid #ddd; text-align: center;} th {background-color: #ff9800; color: white;}\n";
  ptr +="tr:nth-child(even) {background-color: #f2f2f2;}\n";
  ptr +=".btn {display: inline-block; padding: 12px 25px; margin-top: 20px; background: #333; color: white; text-decoration: none; border-radius: 5px; font-weight: bold;}\n";
  ptr +="</style></head><body>\n";
  
  ptr +="<h2>📉 Data Logs</h2>\n";
  ptr +="<table><tr><th>Time</th><th>Temp(&deg;C)</th><th>Hum(%)</th><th>Pres(hPa)</th></tr>\n";
  
  for(int i=0; i<count; i++) {
    ptr += "<tr>";
    ptr += "<td>-" + String(i*4) + "s</td>";
    ptr += "<td><b>" + String(tempHistory[i], 1) + "</b></td>";
    ptr += "<td>" + String(humHistory[i], 0) + "</td>";
    ptr += "<td>" + String(presHistory[i], 0) + "</td>";
    ptr += "</tr>";
  }
  
  ptr +="</table>\n";
  ptr +="<br><a href='/' class='btn'>⬅️ Back</a>\n"; 
  ptr +="</body></html>\n";
  return ptr;
}