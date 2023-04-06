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

%% sector_form (tuning)
num_threshold = 10; %원본 dots일 경우 500~600, preprocessingDots사용할 경우10~20개.
afterTime = 1;
degree_range1 = 30;
%%straight_threshold = 45;

%% track_generator(tuning)
degree_range2 = 30;
rotation_degree = 5;
prev_degree_range = 60; %이 값이 클수록 좀 더 안정적인듯?
radius = 50;

%% second_track_generator (tuning)
degree_range3 = 30;
rotation_degree2 = 5;
prev_degree_range2 = 80;
radius2 = 33;

%% Corner_detector (tuning)
param_Hough = 0.3; % 0.2~0.8의 값 (값이 클수록 corner를 더 늦게 인식)

%% ROI
ROI_Size = 120;

%% control part
%ref 형성시 얼마나 over해서 점을 보낼지 default=1;
over_step=0.5;
% tuning 할 때 tunning 1,2를 조절하면서 하면 됩니다.
tuning1=2;
tuning2=8;

% tunning11의 경우는 tunning1을 1을 기준으로 하는 사람은 2로, 2를 기준으로 하는 사람은 3, 3을 기준으로 하는
% 사람은 4로 조절하고 하면 됩니다.
tuning11=2;

%mpc에서 몇번 째 step을 사용할 지. 3까지는 괜찮은데 그 이상 안 올리는 걸 추천
corner_step=3;
straight_step=2;

%mpc 내부 parameter
Horizon=10;
dt=1;
%gravity
g=9.81;
%inertia
Ix=5.82857000000000e-05;
Iy=7.16914000000000e-05;
Iz=0.0001000000000000;
%mass
m=0.063;
%length
L=0.0624;
%state space
A=zeros(12,12);
A(1,4)=1;
A(2,5)=1;
A(3,6)=1;
A(7,2)=-g;
A(8,1)=g;
A(10,7)=1;
A(11,8)=1;
A(12,9)=1;
B=zeros(12,4);
B(9,1)=1/m;
B(4,2)=1/Ix;
B(5,3)=1/Iy;
B(6,4)=1/Iz;
Total_B=[A B].*dt;
Total_A=eye(12,12);
A_n=cell(20);
temp=Total_A;
for i = 1:20
    A_n{i}=temp;
    temp=temp*Total_A;
end
Gamma=zeros(12*Horizon,12);
for i =1:Horizon
    temp=A_n{i};
    for j=1:12
        for k=1:12
            Gamma(j+12*(i-1),k)=temp(j,k);
        end
    end
end
PI=zeros(240,320);
AB=cell(20);
temp=Total_B;
for i = 1:20
    AB{i}=temp;
    temp=Total_A*temp;
end
zero12=zeros(12,16);
row1=   [Total_B zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12];
row2=   [AB{2} Total_B zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12];
row3=   [AB{3} AB{2} Total_B zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12];
row4=   [AB{4} AB{3} AB{2} Total_B zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12];
row5=   [AB{5} AB{4} AB{3} AB{2} Total_B zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12];
row6=   [AB{6} AB{5} AB{4} AB{3} AB{2} Total_B zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12];
row7=   [AB{7} AB{6} AB{5} AB{4} AB{3} AB{2} Total_B zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12];
row8=   [AB{8} AB{7} AB{6} AB{5} AB{4} AB{3} AB{2} Total_B zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12];
row9=   [AB{9} AB{8} AB{7} AB{6} AB{5} AB{4} AB{3} AB{2} Total_B zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12];
row10=  [AB{10} AB{9} AB{8} AB{7} AB{6} AB{5} AB{4} AB{3} AB{2} Total_B zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12];
row11=  [AB{11} AB{10} AB{9} AB{8} AB{7} AB{6} AB{5} AB{4} AB{3} AB{2} Total_B zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12];
row12=  [AB{12} AB{11} AB{10} AB{9} AB{8} AB{7} AB{6} AB{5} AB{4} AB{3} AB{2} Total_B zero12 zero12 zero12 zero12 zero12 zero12 zero12 zero12];
row13=  [AB{13} AB{12} AB{11} AB{10} AB{9} AB{8} AB{7} AB{6} AB{5} AB{4} AB{3} AB{2} Total_B zero12 zero12 zero12 zero12 zero12 zero12 zero12];
row14=  [AB{14} AB{13} AB{12} AB{11} AB{10} AB{9} AB{8} AB{7} AB{6} AB{5} AB{4} AB{3} AB{2} Total_B zero12 zero12 zero12 zero12 zero12 zero12];
row15=  [AB{15} AB{14} AB{13} AB{12} AB{11} AB{10} AB{9} AB{8} AB{7} AB{6} AB{5} AB{4} AB{3} AB{2} Total_B zero12 zero12 zero12 zero12 zero12];
row16=  [AB{16} AB{15} AB{14} AB{13} AB{12} AB{11} AB{10} AB{9} AB{8} AB{7} AB{6} AB{5} AB{4} AB{3} AB{2} Total_B zero12 zero12 zero12 zero12];
row17=  [AB{17} AB{16} AB{15} AB{14} AB{13} AB{12} AB{11} AB{10} AB{9} AB{8} AB{7} AB{6} AB{5} AB{4} AB{3} AB{2} Total_B zero12 zero12 zero12];
row18=  [AB{18} AB{17} AB{16} AB{15} AB{14} AB{13} AB{12} AB{11} AB{10} AB{9} AB{8} AB{7} AB{6} AB{5} AB{4} AB{3} AB{2} Total_B zero12 zero12];
row19=  [AB{19} AB{18} AB{17} AB{16} AB{15} AB{14} AB{13} AB{12} AB{11} AB{10} AB{9} AB{8} AB{7} AB{6} AB{5} AB{4} AB{3} AB{2} Total_B zero12];
row20=  [AB{20} AB{19} AB{18} AB{17} AB{16} AB{15} AB{14} AB{13} AB{12} AB{11} AB{10} AB{9} AB{8} AB{7} AB{6} AB{5} AB{4} AB{3} AB{2} Total_B];
PI=[row1;row2;row3;row4;row5;row6;row7;row8;row9;row10;row11;row12;row13;row14;row15;row16;row17;row18;row19;row20];
modi_PI=zeros(12*Horizon,16*Horizon);
modi_PI=PI(1:12*Horizon,1:16*Horizon);
%cost matrix
R=eye(16*Horizon);
% R(13,13)=30;
% R(14,14)=30;
% R(15,15)=30;
% R(16,16)=30;
Q=eye(12*Horizon);
% Q(10,10)=10000;
% Q(11,11)=10000;
for i=1:12
   Q(12*(Horizon-1)+i)=0;
end
epsilon=[0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.00001 0.00001 0.001]';