class Spreadsheet(rows: Int) {
    private val s: Array<IntArray> = Array(rows) { IntArray(26) }

    fun setCell(cell: String, value: Int) {
        s[cell.substring(1).toInt() - 1][cell[0] - 'A'] = value
    }

    fun resetCell(cell: String) {
        s[cell.substring(1).toInt() - 1][cell[0] - 'A'] = 0
    }

    fun getValue(formula: String): Int {
        val (a, b) = formula.substring(1).split("+")
        var ans = 0

        when{
            a[0] in 'A'..'Z' -> ans += s[a.substring(1).toInt() - 1][a[0] - 'A']
            else -> ans += a.toInt()
        }

        when{
            b[0] in 'A'..'Z' -> ans += s[b.substring(1).toInt() - 1][b[0] - 'A']
            else -> ans += b.toInt()
        }
        return ans
    }

}

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * var obj = Spreadsheet(rows)
 * obj.setCell(cell,value)
 * obj.resetCell(cell)
 * var param_3 = obj.getValue(formula)
 */
