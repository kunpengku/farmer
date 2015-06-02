$mongodb = new Mongo("10.10.0.1:30003,10.10.0.2:30003,10.10.0.3:30003");
$duoku_apk = $mongodb->selectDB("mcp")->selectCollection("appinfo");

$old = $duoku_apk->findOne(array(
                "id" => $id
            )   
        );  
