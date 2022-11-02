from pyblockworld import World

class Wall:
    def __init__(self, pos: tuple[3], bw: World) -> None:
        self.width: int = 6
        self.height: int = 5
        self.pos: tuple = pos
        self.rotated: bool = False
        self.material_id: str = "default:stone"
        self.bw: World = bw

    def build(self):
        if self.rotated:
            height = self.width
            width  = self.height
        else:
            height = self.height
            width = self.width


        for y in range(-1, height):
            for x in range(1, width + 1):
                self.bw.setBlock(self.pos[0] + x, self.pos[1] + y, self.pos[2], self.material_id)
        pass
    

def b_key_pressed(world:World):
    x,y,z = world.player_position()
    wall = Wall((x, y, z), world)
    wall.build()

    rotated_wall = Wall((x, y, z - 5), world)
    rotated_wall.rotated = True
    rotated_wall.build()
    
world = World()
world.build_key_pressed = b_key_pressed
world.run()