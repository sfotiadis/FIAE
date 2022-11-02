from pyblockworld import World

HEIGHT = 5
WIDTH = 6

class Wall:
    def __init__(self, pos: tuple[3], bw: World) -> None:
        self.width: int = WIDTH
        self.height: int = HEIGHT
        self.pos: tuple = pos
        self.rotated: bool = False
        self.material_id: str = "default:stone"
        self._bw: World = bw

    def build(self) -> None:
        for y in range(-1, self.height):
            if y == 0:
                continue
            for x in range(self.width):
                if self.rotated:
                    self._bw.setBlock(self.pos[0], self.pos[1] + y, self.pos[2] + x, self.material_id)
                else:
                    self._bw.setBlock(self.pos[0] + x, self.pos[1] + y, self.pos[2], self.material_id)
    
class WallWithWindow(Wall):
    def __init__(self, pos: tuple[3], bw: World) -> None:
        super().__init__(pos, bw)
        self.window_material_id: str = "air"

    def build(self) -> None:
        def build_row(y: int):
            for x in range(self.width):
                if self.rotated:
                    self._bw.setBlock(self.pos[0]  , self.pos[1] + y, self.pos[2] + x, self.material_id)
                else:
                    self._bw.setBlock(self.pos[0] + x, self.pos[1] + y, self.pos[2] , self.material_id)
        
        def build_window(y: int):
            for x in range(self.width):
                if self.rotated:
                    if x==2 or x==3: 
                        self._bw.setBlock(self.pos[0], self.pos[1] + y, self.pos[2] + x, self.window_material_id)
                    else:
                        self._bw.setBlock(self.pos[0], self.pos[1] + y, self.pos[2] + x, self.material_id)
                else:
                    if x==2 or x==3:
                        self._bw.setBlock(self.pos[0] + x, self.pos[1] + y, self.pos[2], self.window_material_id)
                    else:
                        self._bw.setBlock(self.pos[0] + x, self.pos[1] + y, self.pos[2], self.material_id)
        
        for y in range(-1, self.height):
            if y == 0:
                continue

            if y == 1 or y == 2:
                build_window(y)
            else:
                build_row(y)
                  
class WallWithDoor(Wall):
    def __init__(self, pos: tuple[3], bw: World) -> None:
        super().__init__(pos, bw)
        self.window_material_id: str = "air"
        
    def build(self):
        def build_row(y: int) -> None:
            for x in range(self.width):
                if self.rotated:
                    self._bw.setBlock(self.pos[0], self.pos[1] + y, self.pos[2] + x, self.material_id)
                else:
                    self._bw.setBlock(self.pos[0] + x, self.pos[1] + y, self.pos[2], self.material_id)
        
        def build_door(y: int):
            for x in range(self.width):
                if self.rotated:
                    if x==2 or x==3:
                        self._bw.setBlock(self.pos[0], self.pos[1] + y, self.pos[2] +  x, self.window_material_id)
                    else:
                        self._bw.setBlock(self.pos[0], self.pos[1] + y, self.pos[2] + x, self.material_id)
                else:
                    if x==2 or x==3:
                        self._bw.setBlock(self.pos[0] + x, self.pos[1] + y, self.pos[2], self.window_material_id)
                    else:
                        self._bw.setBlock(self.pos[0] + x, self.pos[1] + y, self.pos[2], self.material_id)
        
        for y in range(-1, self.height):
            if y == 0:
                continue

            if y <= 2:
                build_door(y)
            else:
                build_row(y)

class Roof:
    def __init__(self, pos: tuple[3], bw: World) -> None:
        self.width: int = WIDTH
        self.depth: int = WIDTH
        self.pos: tuple = pos
        self.material_id: str = "default:brick"
        self.__bw: World = bw

    def build(self) -> None:
        for z in range(self.depth):
            for x in range(self.width):
               self.__bw.setBlock(self.pos[0] + x, self.pos[1] + HEIGHT, self.pos[2] + z, self.material_id)
        pass

class House:
    def __init__(self, pos: tuple[3], bw: World) -> None:
        self.pos: tuple[3] = pos
        self.__bw: World = bw
        self.wallFront: Wall = WallWithDoor((self.pos[0] , self.pos[1], WIDTH - 1 + self.pos[2]), self.__bw)
        self.wallLeft: Wall = WallWithWindow((WIDTH - 1 + self.pos[0], self.pos[1], self.pos[2]), self.__bw)
        self.wallRight: Wall = WallWithWindow((self.pos[0], self.pos[1], self.pos[2]), self.__bw)
        self.wallBack: Wall = Wall((self.pos[0], self.pos[1], self.pos[2] ), self.__bw)
        self.roof: Roof = Roof((self.pos[0], self.pos[1], self.pos[2]),self.__bw)

    def build(self) -> None:
        self.wallFront.build()
        self.wallLeft.rotated = True 
        self.wallLeft.build()
        self.wallRight.rotated = True
        self.wallRight.build()
        self.wallBack.build()
        self.roof.build()

    def change_wall_material(self, new_material_id: str) -> None:
        self.wallFront.material_id = new_material_id
        self.wallLeft.material_id = new_material_id
        self.wallRight.material_id = new_material_id
        self.wallBack.material_id = new_material_id

'''
#build two plain walls
def b_key_pressed(world:World):
    x,y,z = world.player_position()
    wall = Wall((x, y, z), world)
    wall.build()

    rotated_wall = Wall((x, y, z), world)
    rotated_wall.rotated = True
    rotated_wall.build()

#build two walls with windows
def b_key_pressed(world:World):
    x,y,z = world.player_position()
    wall = WallWithWindow((x, y, z), world)
    wall.build()

    rotated_wall = WallWithWindow((x, y, z), world)
    rotated_wall.rotated = True
    rotated_wall.build()

#build two walls with doors
def b_key_pressed(world:World):
    x,y,z = world.player_position()
    wall = WallWithDoor((x, y, z), world)
    wall.build()

    rotated_wall = WallWithDoor((x, y, z), world)
    rotated_wall.rotated = True
    rotated_wall.build()

#build default house
def b_key_pressed(world:World):
    x,y,z = world.player_position()
    house = House((x, y, z), world)
    house.build()

#build with another material
def b_key_pressed(world:World):
    x,y,z = world.player_position()
    house = House((x, y, z), world)
    house.change_wall_material("default:sand")
    house.build()

'''
def b_key_pressed(world:World):
    x,y,z = world.player_position()
    house = House((x, y, z), world)
    house.change_wall_material("default:sand")
    house.build()


world = World()
world.build_key_pressed = b_key_pressed
world.run()