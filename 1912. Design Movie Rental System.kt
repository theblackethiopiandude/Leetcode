class MovieRentingSystem(n: Int, entries: Array<IntArray>) {
    data class Movie(val shop: Int, val movie: Int, val price: Int)
    val movieMap: MutableMap<Int, TreeSet<Movie>> = mutableMapOf() 
    val rented: TreeSet<Movie> = TreeSet(compareBy<Movie> { m -> m.price }.thenBy { m -> m.shop }.thenBy { m -> m.movie })
    val allMovies: MutableMap<Pair<Int, Int>, Movie> = mutableMapOf()

    init{
        entries.forEach {
            val m = Movie(it[0], it[1], it[2]);
            movieMap.getOrPut(m.movie) { TreeSet(compareBy<Movie> { m -> m.price }.thenBy { m -> m.shop }) }
            .add(m)
            allMovies[m.shop to m.movie] = m
        }
    }

    fun search(movie: Int): List<Int> {
        val movies = movieMap[movie]

        if(movies != null){
            return movies.take(5).map{it.shop}
        }

        return listOf()
    }

    fun rent(shop: Int, movie: Int) {
        val m = allMovies[shop to movie]!!
        movieMap[movie]!!.remove(m)

        rented.add(m)
    }

    fun drop(shop: Int, movie: Int) {
        val m = allMovies[shop to movie]!!
        rented.remove(m)

        movieMap[m.movie]!!.add(m)
    }

    fun report(): List<List<Int>> {
        return rented.take(5).map{listOf(it.shop, it.movie)}
    }

}

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * var obj = MovieRentingSystem(n, entries)
 * var param_1 = obj.search(movie)
 * obj.rent(shop,movie)
 * obj.drop(shop,movie)
 * var param_4 = obj.report()
 */
