var express= require('express');
var morgan = require('morgan');
var bodyParser = require('body-parser');
var app = express();
app.use(bodyParser.urlencoded({
  extended:true
}));
app.use(bodyParser.json());
var lat=13.11527;
var long=77.63475;
var det=0;
app.get('/',function(req,res){
  res.sendFile(__dirname + "/index.html");
});
app.get('/getdata/:lat',function(req,res){
  det=1;
  res.send("done added!")

});
app.get('/seedata',function(req,res){
  if(det==0)
  {
  	console.log(det);
  	res.send("0 0");

  }
  else
  {
   console.log(det);
  resp = lat + " "+ long;
  det=0;
  res.send(resp);
}
});
app.listen(5000,function(){
  console.log('running on port 5000!!');
});

