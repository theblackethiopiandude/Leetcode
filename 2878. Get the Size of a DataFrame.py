import pandas as pd

def getDataframeSize(players: pd.DataFrame) -> List[int]:
    row, column = players.shape
    return [row, column]


def getDataframeSize(players: pd.DataFrame) -> List[int]:
    return list(players.shape)
