from pyblockworld import World
from blockworld import House
import unittest

class HouseTest(unittest.TestCase):
    def setUp(self):
        self.house = House((1,2,3), World())
        self.house.change_wall_material("default:sand")
    
    def test_change_wall_material(self):
        self.assertEqual(self.house.wallFront.material_id, "default:sand")
        self.assertEqual(self.house.wallBack.material_id, "default:sand")
        self.assertEqual(self.house.wallLeft.material_id, "default:sand")
        self.assertEqual(self.house.wallRight.material_id, "default:sand")

if __name__ == "__main__":
    houseTest = HouseTest()
    houseTest.setUp()
    houseTest.test_change_wall_material()
    print("test passed")
