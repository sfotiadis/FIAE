from pyblockworld import World

class Wall:
    def __init__(self, pos: tuple[3], bw: World) -> None:
        self.width: int = 6
        self.height: int = 5
        self.pos: tuple = pos
        self.rotated: bool = False
        self.material_id: str = "default:stone"
        self._bw: World = bw

    def build(self):
        for y in range(-1, self.height):
            if y == 0:
                continue
            for x in range(1, self.width + 1):
                if self.rotated:
                    self._bw.setBlock(self.pos[0], self.pos[1] + y, self.pos[2] -1 + x, self.material_id)
                else:
                    self._bw.setBlock(self.pos[0] + x, self.pos[1] + y, self.pos[2], self.material_id)
    
class WallWithWindow(Wall):
    def __init__(self, pos: tuple[3], bw: World) -> None:
        super().__init__(pos, bw)
        self.window_material_id: str = "air"

    def build(self):
        def build_row(y: int):
            for x in range(1, self.width + 1):
                if self.rotated:
                    self._bw.setBlock(self.pos[0], self.pos[1] + y, self.pos[2] + x, self.material_id)
                else:
                    self._bw.setBlock(self.pos[0] + x, self.pos[1] + y, self.pos[2], self.material_id)
        
        def build_window(y: int):
            for x in range(1, self.width + 1):
                if self.rotated:
                    if x==3 or x==4:
                        self._bw.setBlock(self.pos[0], self.pos[1] + y, self.pos[2] +  x, self.window_material_id)
                    else:
                        self._bw.setBlock(self.pos[0], self.pos[1] + y, self.pos[2] + x, self.material_id)
                else:
                    if x==3 or x==4:
                        self._bw.setBlock(self.pos[0] + x, self.pos[1] + y, self.pos[2], self.window_material_id)
                    else:
                        self._bw.setBlock(self.pos[0] + x, self.pos[1] + y, self.pos[2], self.material_id)
        
        for y in range(-1,self.height):
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
        def build_row(y: int):
            for x in range(1, self.width + 1):
                if self.rotated:
                    self._bw.setBlock(self.pos[0], self.pos[1] + y, self.pos[2] + x, self.material_id)
                else:
                    self._bw.setBlock(self.pos[0] + x, self.pos[1] + y, self.pos[2], self.material_id)
        
        def build_door(y: int):
            for x in range(1, self.width + 1):
                if self.rotated:
                    if x==3 or x==4:
                        self._bw.setBlock(self.pos[0], self.pos[1] + y, self.pos[2] +  x, self.window_material_id)
                    else:
                        self._bw.setBlock(self.pos[0], self.pos[1] + y, self.pos[2] + x, self.material_id)
                else:
                    if x==3 or x==4:
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

'''
def b_key_pressed(world:World):
    x,y,z = world.player_position()
    wall = Wall((x, y, z), world)
    wall.build()

    rotated_wall = Wall((x, y, z - 5), world)
    rotated_wall.rotated = True
    rotated_wall.build()
'''

def b_key_pressed(world:World):
    x,y,z = world.player_position()
    wall = WallWithWindow((x, y, z), world)
    wall.build()
    rotated_wall = WallWithWindow((x, y, z), world)
    rotated_wall.rotated = True
    rotated_wall.build()

    door_wall = WallWithDoor((x , y, z + 7), world)
    door_wall.build()
    rotated_door_wall = WallWithDoor((x + 7, y, z), world)
    rotated_door_wall.rotated = True
    rotated_door_wall.build()


world = World()
world.build_key_pressed = b_key_pressed
world.run()