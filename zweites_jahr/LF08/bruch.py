import math

class Bruch:
    def __init__(self, zaehler: int, nenner: int):
        self.zaehler = zaehler
        self.nenner = nenner

    def erweitern(self, k: int) -> None:
        self.zaehler *= k
        self.nenner *= k
    
    def kuerzen(self, k: int) -> None:
        self.zaehler /= k
        self.nenner /= k
    
    def vollstaendigKuerzen(self) -> None:
        teiler = math.gcd(self.zaehler, self.nenner)
        self.kuerzen(teiler)

