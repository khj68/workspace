const MongoClient = require('mongodb').MongoClient;
const url = "mongodb://localhost:27017/";

MongoClient.connect(url, function(err, db)) {
  if(err) throw err;
  let dbo = db.db("recipes");
  dbo.createCollection
  ClipboardEvent.collection("")
}

app.use(multer({ dest: './uploads/', 
  rename : function (fieldname, filename){
    return filename;
  },
}));