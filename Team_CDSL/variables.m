%% frame size
FRAME_SIZE_HEIGHT=120;
FRAME_SIZE_WIDTH=160;
COG_X=FRAME_SIZE_HEIGHT/2;
COG_Y=FRAME_SIZE_WIDTH/2;

%% binarizer
BINARIZER_THRESHOLD = 100;
G_B_GAIN = 2;

%% 4dots picker
S = 80;

%% Landing mark detector
DISK_KERNEL = 11;

%% sector_form (tunning)
num_threshold = 200; %원본 dots일 경우 500~600, preprocessingDots사용할 경우10~20개.
degree_range1 = 30;
straight_threshold = 590;

%% track_generator(tunning)
degree_range2 = 30;
rotation_degree = 5;
prev_degree_range = 60; %이 값이 클수록 좀 더 안정적인듯?
radius = 50;

%% second_track_generator (tunning)
degree_range3 = 30;
rotation_degree2 = 5;
prev_degree_range2 = 80;
radius2 = 33;

