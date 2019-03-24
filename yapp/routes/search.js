module.exports = function(app, Recipe){

  app.get('/api/recipes', function(req,res)){
    Recipe.find((err, recipes) => {
      if(err) return res.status(500).send({error: 'database failure'});
      res.json(recipes);
    });
  }

  app.get('/api/recipes/:tag', function(req,res){

  })

  app.post('/api/recipes', function(req,res){
    let recipe = new Recipe();
    recipe.name = req.body.name;
    recipe.glass = req.body.glass;
    recipe.percent = req.body.percent;
    recipe.description = req.body.description;
    recipe.tag = req.body.tag;
    recipe.ingredient = req.body.ingredient;

    recipe.save(function(err){
      if(err){
        res.json({result:0});
        return;
      }

      res.json({result:1});
    })
  })
  
  // app.post('/api/photo', function(req,res){
  //   let newRecipe = new Recipe();
  //   newRecipe.image.data = fs.readFileSync(/*imgPath*/ req.files.recipePhoto.path)
  //   newRecipe.image.contentType = 'image/png';
  //   newRecipe.save()
  // })
}