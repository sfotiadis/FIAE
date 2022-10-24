from pyblockworld import World

def b_key_pressed(world:World):
    x,y,z = world.player_position()

    world.setBlock(x+1,y-1,z, "default:sand")
    world.setBlock(x+2,y-1,z, "default:stone")
    world.setBlock(x+3,y-1,z, "default:grass")
    
world = World()
world.build_key_pressed = b_key_pressed
world.run()