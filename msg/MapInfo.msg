# This hold basic information about the characterists of each sub-map
Header header 
float32 resolution             # The map resolution [m/cell]
uint32 width                   # Map width [cells]
uint32 height                  # Map height [cells]
#geometry_msgs/Pose origin      # The origin of the map.
uint32 num                     # num of obstacles
obs[] obsData                  # obstacles