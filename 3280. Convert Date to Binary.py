def convertDateToBinary(self, date: str) -> str:
        year, month, day = [bin(int(d))[2:] for d in date.split("-")]
        return f"{year}-{month}-{day}"
