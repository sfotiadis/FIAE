class Zaehler:
    def __init__(self, grenze: int = 0):
        self.grenze = grenze
        self.stand = 0

    def reset(self) -> None:
        self.stand = 0 
    
    def hochzaehlen(self) -> None:
        self.stand += 1
        if self.grenze != 0 : self.stand %= self.grenze 

