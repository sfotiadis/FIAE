class Auto:
    def __init__(self, hersteller: str, laufleistung: int, preis: float, farbe: str, 
                    unfallwagen: bool, kraftstoff: str, leistung: float):
        self.hersteller = hersteller
        self.laufleistung = laufleistung
        self.preis = preis
        self.farbe = farbe
        self.unfallwagen = unfallwagen
        self.kraftstoff = kraftstoff
        self.leistung = leistung
    
    def ausgabe(self) -> None:
        print("Hersteller:", self.hersteller)
        print(f"Preis: {self.preis} EUR")
        print(f"Motor: {self.leistung} PS ({self.kraftstoff})")
        print(f"KM-Stand: {self.laufleistung} km")
        print("Farbe:", self.farbe)
        if not self.unfallwagen : print("unfallfrei")

