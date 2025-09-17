class FoodRatings(foods: Array<String>, cuisines: Array<String>, ratings: IntArray) {
    private val foodInfo = mutableMapOf<String, Pair<String, Int>>()

    private val cuisineMap = mutableMapOf<String, TreeSet<Pair<Int, String>>>()

    init{
        for((i, food) in foods.withIndex()){
            foodInfo[food] = cuisines[i] to ratings[i]
            
            cuisineMap.putIfAbsent(cuisines[i], TreeSet(compareByDescending<Pair<Int, String>> { it.first }
                .thenBy { it.second }))
            
            cuisineMap[cuisines[i]]!!.add(ratings[i] to food)
        }
    }

    fun changeRating(food: String, newRating: Int) {
        val (cuisine, oldRating) = foodInfo[food]!!

        cuisineMap[cuisine]!!.remove(oldRating to food)

        cuisineMap[cuisine]!!.add(newRating to food)

        foodInfo[food] = cuisine to newRating
    }

    fun highestRated(cuisine: String): String {
        return cuisineMap[cuisine]!!.first().second
    }

}

/**
 * Your FoodRatings object will be instantiated and called as such:
 * var obj = FoodRatings(foods, cuisines, ratings)
 * obj.changeRating(food,newRating)
 * var param_2 = obj.highestRated(cuisine)
 */
