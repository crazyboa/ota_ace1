String webTail="</body> </html>";

String webMenu="";
String webHtml="";

//***********************************************************************
char Head[] PROGMEM = R"=====(
<html>
  <head>
    <meta name='viewport' content='width=device-width, initial-scale=1.0'/>
    <meta http-equiv='Content-Type' content='text/html;charset=utf-8' />
    <style>
      table, th, td {
        padding: 4px;
      }
      body {
        background: #eab0dc;
        font-family: "Lato", sans-serif;
      }
      .button {
        border: none;
          border-color:black;
          color: white;
          padding: 20px;
          text-align: center;
          text-decoration: none;
          display: inline-block;
          font-size: 16px;
          margin: 4px 2px;
          cursor: pointer;
        }
        .buttonMenu {
          padding: 5px 24px;
          margin-left:20%;
          background-color:black;
          border: none;
          border-color:black;
          color:white;
          text-align: left;
          text-decoration: none;
          display: inline-block;
          font-size: 16px;
          margin: 4px 2px;
          cursor: pointer;
        }
        .sidenav {
          height: 100%;
          width: 0;
          position: fixed;
          z-index: 1;
          top: 0;
          left: 0;
          background-color: #111;
          overflow-x: hidden;
          transition: 0.5s;
          padding-top: 60px;
        }
        .sidenav a {
          padding: 8px 8px 8px 32px;
          text-decoration: none;
          font-size: 18px;
          color: #818181;
          display: block;
                transition: 0.3s;
        }
        .sidenav a:hover {
          color: #f1f1f1;
        }
        .sidenav .closebtn {
          position: absolute;
          top: 0;
          right: 25px;
          font-size: 36px;
          margin-left: 50px;
        }
        .button-box {background-color:#ff8000;color: white;border: none;padding: 6px 15px;}
        .button-on {border-radius: 100%; background-color: #4CAF50;}
        .button-off {border-radius: 100%;background-color: #707070;}
        .button-ledon {border-radius: 100%; padding: 10px; font-size: 8px; margin: 0px 0px; background-color: #ff4500;}
        .button-ledoff {border-radius: 100%; padding: 10px; font-size: 8px; background-color: #707070;}
  </style>
)=====";

char RootScript[] PROGMEM = R"=====(
  <script>
    var Socket;
    function init() {
      Socket = new WebSocket('ws://' + window.location.hostname + ':81/');
      Socket.onmessage = function(event){
        var data = JSON.parse(event.data);
        console.log(data.tickcount);
        document.getElementById("tickcount").innerHTML = data.tickcount;
      }
    }
    function openNav() {
      document.getElementById("mySidenav").style.width = "150px"; 
    }
    function closeNav() {
      document.getElementById("mySidenav").style.width = "0";
    }
  </script> 
</head>
<body onload="javascript:init()">
)=====";


char HeadScript[] PROGMEM = R"=====(
  <script>
    var Socket;
    function init() {
      Socket = new WebSocket('ws://' + window.location.hostname + ':81/');
      Socket.onmessage = function(event){
      }
    }
    function sendOption(){
      document.getElementById("ssidSelected").value = document.getElementById("ssid").value;
      //Socket.send("$"+document.getElementById("ssid").value);
    }
    function sendAct(valueIn){
      Socket.send(valueIn);
    }
    function sendDownOptionLocal() {
      document.getElementById("downFile").innerHTML=document.getElementById("downloadLocal").value;
      var s="#"+"{'act':2,'value':'"+document.getElementById("downloadLocal").value+"'}";
      Socket.send(s);
    }
    function sendDownOptionAws() {
      document.getElementById("downFile").innerHTML=document.getElementById("downloadAws").value;
      var s="#"+"{'act':2,'value':'"+document.getElementById("downloadAws").value+"'}";
      Socket.send(s);
    }
    function openNav() {
      document.getElementById("mySidenav").style.width = "150px"; 
    }
    function closeNav() {
      document.getElementById("mySidenav").style.width = "0";
    }
  </script>
</head>
<body onload="javascript:init()">
)=====";

char Body[] PROGMEM = R"=====(
  <br><br>?????? ?????? down-permwareBasic.bin
  <br>
  <span class="dht-labels">tickcount</span> 
    <span id="tickcount">%tickcount%</span>
  <sup class="units">&deg;C</sup>
  
)=====";

char Menu[] PROGMEM = R"=====(
  <div id='mySidenav' class='sidenav'>
  <a href='javascript:void(0)' class='closebtn' onclick='closeNav()'>&times;</a>
  <a href='/'>???</a>
  <a href='/download'>????????????</a>
  <a href='/wifi'>??????????????????</a>
  <a href='/config'>????????????</a>
  <a href='https://github.com/kdi6033/IoT' target='_blank'>?????????</a>
  <a href='http://acerna.duckdns.org' target='_blank'>??????</a>
  </div>
  <span style='font-size:30px;cursor:pointer' onclick='openNav()'>&#9776; </span>
  ????????????
)=====";

char Download[] PROGMEM = R"=====(
  <br><br>????????????
  ????????? ????????? ???????????? ???????????? ????????? ?????????????????? ?????????.
  <div> <button id="onButton" class='button button-box' onclick="sendAct('#'+'{\'act\':1}');">??????????????? ???????????????</button> </div>  
  <hr>
  <br>????????? ???????????? ???????????? ?????? ????????? ?????? ??? ?????? [????????????] ????????? ????????????. 
  <br>????????? ??????????????? ???????????? ?????? ?????????.<br><br>

  <br>[???????????? ????????????]
  <br>- ???????????? ??? ??????????????? ????????????/?????? ????????? MQTT ????????? ??????
  <br>- ???????????? ????????? ????????????
  <br>- MQTT????????? ????????? ??????????????? ???????????? ????????????/?????? <br>
  <select id='downloadLocal' name='downloadLocal' onclick='sendDownOptionLocal();'>
    <option value='down-local-02.bin'>2 [sensecube] PE-300</option>";
    <option value='down-local-03.bin'>3 [allsensing] klumi</option>";
    <option value='down-local-04.bin'>4 [sensecube] KSM-8900</option>";
    <option value='down-local-05.bin'>5 [allsensing] ??????????????????</option>";
    <option value='down-local-06.bin'>6 [LS??????] XGB XEC-DR14E </option>";
    <option value='down-local-07.bin'>7 [D1 mini shield] ?????????????????? DHT11</option>";
    <option value='down-local-08.bin'>8 [??????] RY-WSY301</option>";
    <option value='down-local-09.bin'>9 [??????] MP-508E</option>";
    <option value='down-local-10.bin'>10 ???????????????</option>";
    <option value='down-local-11.bin'>11 ????????????</option>";
    <option value='down-local-12.bin'>12 PLC-RS485</option>";
    <option value='down-local-13.bin'>13 [??????]????????????</option>";
    <option value='down-local-14.bin'>14 [LS??????] MASTER-K120s</option>";
  </select>
  <br><br>[?????????????????? ????????? ?????????????????? ????????????]
  <br>????????? ????????? ???????????? ???????????? ???????????? ????????????/?????? ?????? ????????????
  <br>E-mail ID??? ?????? ???????????? ????????? ?????? ?????? ????????? ????????? ??? ??? ??????
  <br>??????????????? : <a href='http://acerna.duckdns.org'>http://acerna.duckdns.org/</a>
  <br>
  <select id='downloadAws' name='downloadAws' onclick='sendDownOptionAws();'>
    <option value='down-aws-02.bin'>2 [sensecube] PE-300</option>";
    <option value='down-aws-03.bin'>3 [allsensing] klumi</option>";
    <option value='down-aws-04.bin'>4 [sensecube] KSM-8900</option>";
    <option value='down-aws-05.bin'>5 [allsensing] ??????????????????</option>";
    <option value='down-aws-06.bin'>6 [LS??????] XGB XEC-DR14E </option>";
    <option value='down-aws-07.bin'>7 [D1 mini shield] ?????????????????? DHT11</option>";
    <option value='down-aws-08.bin'>8 [??????] RY-WSY301</option>";
    <option value='down-aws-09.bin'>9 [??????] MP-508E</option>";
  </select>
  <br>???????????? ?????? ?????? : <span id="downFile">????????????</span>
  <button id="onButton" class='button button-box' onclick="sendAct('#'+'{\'act\':3}');">????????????</button>
  <hr>
)=====";

char Manual[] PROGMEM = R"=====(
  <br><br>?????????
)=====";

char Tail[] PROGMEM = R"=====(
</body>
</html>
)=====";

void handleRoot() {
  String s;
  s=FPSTR(Head);
  s+=FPSTR(RootScript);
  s+=FPSTR(Menu);
  s+=FPSTR(Body);
  s+=FPSTR(Tail);
  server.send(200, "text/html", s);
}

void handleOn() {
  act=server.arg("act").toInt();
  //int value=server.arg("value").toInt();

  Serial.println("----------------------------");
  Serial.println(act);
  //Serial.println(no);
  //Serial.println(value);

  if(act==2) {
    server.arg("ipMqtt").toCharArray(ipMqtt, sizeof(ipMqtt) - 1);
    server.arg("userMqtt").toCharArray(userMqtt, sizeof(userMqtt) - 1);
    server.arg("passwordMqtt").toCharArray(passwordMqtt, sizeof(passwordMqtt) - 1);
    server.arg("email").toCharArray(email, sizeof(email) - 1);
    Serial.println(ipMqtt);
    Serial.println(userMqtt);
    Serial.println(passwordMqtt);
    Serial.println(email);
    saveConfig();
  }
  GoHome();
}

void GoHome() {
  String s;
  s="<meta http-equiv='refresh' content=\"0;url='http://"+ipAct+"/'\">";
  server.send(200, "text/html", s);
}

void GoHomeWifi() {
  String s,ipS;
  IPAddress ip;
  if(bootMode==1)
    ip = apIP;
  else
    ip = WiFi.localIP();
  
  ipS=String(ip[0])+"."+String(ip[1])+"."+String(ip[2])+"."+String(ip[3]);
    s="<meta http-equiv='refresh' content=\"0;url='http://"+ipS+"/wifi'\">";
  server.send(200, "text/html", s);
}

void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}

//???????????? ????????????
String sensWifi(int in) {
  if(in < -80)
    return "9783";
  else if(in < -70)
    return "9779";
  else if(in < -50)
    return "9777";
  else 
    return "9776";
}

void handleWifi() {
  String s; 
  String s1= String(ssid);
  s=s+"<h1>Wifi ??????</h1>";
  if (server.client().localIP() == apIP) {
    s=s+String("<p>????????? AP: 192.168.4.1") + "</p>";
  } else {
    s=s+"<p>????????? ???????????? " + String(ssid) + "</p>";
  }

  Serial.println("scan start");
  int n = WiFi.scanNetworks();
  Serial.println("scan done");

  if (n > 0) {
    s+="<select id='ssid' name='ssid' onclick=\"sendOption();\">";
    for (int i = 0; i < n; i++) {
      s+="<option value='"+WiFi.SSID(i)+"'>";
      s+=WiFi.SSID(i) + String((WiFi.encryptionType(i) == ENC_TYPE_NONE)?" ":"&emsp;&#128274")+"&emsp; &#"+ sensWifi(WiFi.RSSI(i));
      s+="</option>";
    }
    s+="</select>";
  } 
  else 
    s=s+"<br>No WLAN found";

  s=s+"<p><a href='/wifi'>??????????????? ????????? ?????? ???????????????.</a></p>";
  s+="<form method='POST' action='/wifisave'>";
  s+="<table>";
    s+="<tr>";
      s+="<th>???????????? ??????</th>";
      s+="<th><input type='text' id='ssidSelected' value='"+(String)ssid+"' name='n'/></th>";
    s+="</tr>";
    s+="<tr>";
      s+="<th>????????????</th>";
      s+="<th><input type='password' value='"+(String)password+"' name='p'/></th>";
    s+="</tr>";
    s+="<tr>";
      s+="<th></th>";
      s+="<th><input type='submit' value='    ???  ???    ' style='background-color:#ff8000;color: white;border: none;padding: 6px 15px;'/></form></th>";
    s+="</tr>";
  String sOut;
  sOut=FPSTR(Head);
  sOut+=FPSTR(HeadScript);
  sOut+=FPSTR(Menu);
  sOut+=s;
  sOut+=FPSTR(Tail);
  server.send(200, "text/html", sOut);
}
/** Handle the WLAN save form and redirect to WLAN config page again */
void handleWifiSave() {
  GoHome();
  Serial.println("wifi save");
  server.arg("n").toCharArray(ssid, sizeof(ssid) - 1);
  server.arg("p").toCharArray(password, sizeof(password) - 1);
  server.sendHeader("Location", "wifi", true);
  server.sendHeader("Cache-Control", "no-cache, no-store, must-revalidate");
  server.sendHeader("Pragma", "no-cache");
  server.sendHeader("Expires", "-1");
  server.send ( 302, "text/plain", "");  // Empty content inhibits Content-length header so we have to close the socket ourselves.
  server.client().stop(); // Stop is needed because we sent no content length
  saveConfig();
  //connect = strlen(ssid) > 0; // Request WLAN connect with new credentials if there is a SSID
  Serial.println(WiFi.waitForConnectResult());
  Serial.println(ssid);
  Serial.println(password);
  Serial.println("Reset");
  ESP.reset();
}

void handleScan() {
  String s;
    s="{\"mac\":\""+sMac+"\",\"ip\":\""+WiFi.localIP().toString()+"\",\"\temp\":"+counter+"}";
  server.send(200, "text/html", s);
}

void handleConfig() {
  String s;
  s="<br><br>???????????? mqtt ????????? ???????????? ?????? ???????????? ??????????????? ????????? ???????????? ????????? ?????????.<br>";
  s+="<br> ????????? ?????? http://acerna.link ??????????????? ???????????? ??? email??? ???????????????.<br>";
  s+="<form action='/on'>";
  s+="<input type='hidden' name='act' value='2'>";
  s+="<table>";
    s+="<tr>";
      s+="<th>mqtt?????? IP</th>";
      s+="<th><input type='text' value='"+(String)ipMqtt+"' name='ipMqtt'/></th>";
    s+="</tr>";
    s+="<tr>";
      s+="<th>???????????????</th>";
      s+="<th><input ttype='text' value='"+(String)userMqtt+"' name='userMqtt'/></th>";
    s+="</tr>";
    s+="<tr>";
      s+="<th>????????????</th>";
      s+="<th><input type='password' value='"+(String)passwordMqtt+"' name='passwordMqtt'/></th>";
    s+="</tr>";
    s+="<tr>";
      s+="<th>email</th>";
      s+="<th><input type='text' value='"+(String)email+"' name='email'/></th>";
    s+="</tr>";
    s+="<tr>";
      s+="<th></th>";
      s+="<th><input type='submit' value='    ???  ???    ' style='background-color:#ff8000;color: white;border: none;padding: 6px 15px;'/></th>";
    s+="</tr>";
  s+="</table>";
  s+="</form>";

  String sOut;
  sOut=FPSTR(Head);
  sOut+=FPSTR(HeadScript);
  sOut+=FPSTR(Menu);
  sOut+=s;
  sOut+=FPSTR(Tail);
  server.send(200, "text/html", sOut);
}

void handleDownload() {
  String s;
  s=FPSTR(Head);
  s+=FPSTR(HeadScript);
  s+=FPSTR(Menu);
  if(FirmwareVer != FirmwareVerServer) {
    s+="<br><br>????????? ????????? ?????? ???????????????. ????????? ??????????????? ?????????.<br>";
    s+="????????? ??????"+FirmwareVerServer+"&emsp; ????????????"+FirmwareVer;
  }
  s+=FPSTR(Download);
  s+=FPSTR(Tail);
  server.send(200, "text/html", s);
}

void handleManual() {
  String s;
  s=FPSTR(Head);
  s+=FPSTR(HeadScript);
  s+=FPSTR(Menu);
  s+=FPSTR(Manual);
  s+=FPSTR(Tail);
  server.send(200, "text/html", s);
}
