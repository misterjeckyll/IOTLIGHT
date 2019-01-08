
void sendcontent(){
  String mem[6];
  for(int toggle =0;toggle < 6 ;toggle++){
    mem[toggle] = "";
    if(state == toggle)mem[toggle]="checked";
  }
  String head = "";
  head+="<head>\
    <title>IOTLIGHT</title>\
    <meta charset='utf-8' />\
    <style type='text/css'>\
    * { box-sizing: border-box;}\
    input[type='radio'], input[type='checkbox']{display: none;}\
    .tgl + .tgl-btn {\
      display: block;\
      width: 4em;\
      height: 2em;\
      border-radius: 2em;\
      padding: 2px;\
      position: relative;\
      cursor: pointer;\
      background: #f0f0f0;\
      transition: all .4s ease;\
    }\
    .tgl + .tgl-btn:after {\
      position: relative;\
      display: block;\
      content: '';\
      width: 50%;\
      height: 100%;\
      left: 0;\
    }\
    .tgl:checked + .tgl-btn:after {left: 50%;}\
    .tgl + .tgl-btn:after {\
      border-radius: 50%;\
      background: #fff;\
      transition: all .2s ease;\
    }\
    .tgl:checked + .tgl-btn {background: #9FD6AE;}\
  </style>\
  <script type='text/javascript'>\
    function sleep(ms) {\
      return new Promise(resolve => setTimeout(resolve, ms));\
    }\
    async function update(element) {\
      await sleep(400);\
      element.form.submit();\
      console.log('submited');\
    }\
  </script>\
  </head>";
  String body = "\
    <body>\
      <h1>Hello from the IOTLIGHT !</h1>\
      <p>This is a very basic http webserver hosted on a wifi enabled microcontoler</p>\
      <h2>Colours</h2>\
      <a href='/couleur?r=255&g=0&b=0'><button>RED</button></a>\
      <a href='/couleur?r=0&g=255&b=0'><button>GREEN</button></a>\
      <a href='/couleur?r=0&g=0&b=255'><button>BLUE</button></a>";
    body +=getStateForm();
    body += "</body>";
  String content = "<!DOCTYPE html><html>"+head+ body+"</html>";
  //server.send(200,"text/html","<!DOCTYPE html><html><head></head><body></body></html>");
  server.send(200, "text/html", content);
}

String getStateForm(){
  /**
   * auto generate html for a 
   * dynamic form with all the possible states
   */
  String form="<form action='/state' method='GET'>";
  for(int toggle = 0;toggle < NBSTATE ;toggle++){
    String id = stateStr[toggle];
    form+="<div>"+id+"<input onchange='update(this);' id='"+id+"' class='tgl' name='s' value='"+id+"' type='radio' ";
    form+=((state == toggle)?"checked" : "");
    form+="/><label class='tgl-btn' for='"+id+"'></label></div>";
  }
  return form;
}

