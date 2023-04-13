%% Frame condition
VisualParam.H = 120; %height of frame
VisualParam.W = 160; %width of frame
VisualParam.CX=60; % Center of X
VisualParam.CY=80; % Center of Y

%% Binarizer
VisualParam.R_THRESHOLD = 150;

%% Corner_detector
VisualParam.HOUGH = 0.3;

%% Landing mark detector
DISK_SIZE = 12;
VisualParam.ROI_SIZE = 120;

%% Landing checker
VisualParam.landing_threshold = 10;

%% go_straight (기존 sector_form)
after_time = 0.5;
VisualParam.dots_threshold = 8; % 기존 num_threshold
VisualParam.angle_of_view1= 30; % 기존 degree_range1

%% second_ref_generator
VisualParam.angle_of_rotation = 5; % 기존 rotation_degree2
VisualParam.angle_of_view2 = 30; % 기존 degree_range3
VisualParam.erased_angle2 = 80; % 기존 prev_degree_range2
VisualParam.radius2 = 33; % 기존 radius2

%% new_track_generator
VisualParam.angle_of_view3 = 30; % 기존 degree_range2
VisualParam.erased_angle3 = 60; % 기존 prev_degree_range
VisualParam.radius3 = 50; % 기존 radius

%% ref extender
MPCParam.over_step=0.3;
MPCParam.straight_over_step = MPCParam.over_step+1;

MPCParam.tuning1=3;
MPCParam.tuning2=7;

MPCParam.tuning11=2;

%% MPC
MPCParam.corner_step=1;
MPCParam.straight_step=2;

%mpc parameter
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
MPCParam.Gamma=zeros(12*Horizon,12);
for i =1:Horizon
temp=A_n{i};
for j=1:12
for k=1:12
MPCParam.Gamma(j+12*(i-1),k)=temp(j,k);
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
MPCParam.modi_PI=zeros(12*Horizon,16*Horizon);
MPCParam.modi_PI=PI(1:12*Horizon,1:16*Horizon);
%cost matrix
MPCParam.R=eye(16*Horizon);
% MPCParam.R(13,13)=30;
% MPCParam.R(14,14)=30;
% MPCParam.R(15,15)=30;
% MPCParam.R(16,16)=30;
MPCParam.Q=eye(12*Horizon);
% MPCParam.Q(10,10)=10000;
% MPCParam.Q(11,11)=10000;
for i=1:12
MPCParam.Q(12*(Horizon-1)+i)=0;
end
MPCParam.epsilon=[0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.00001 0.00001 0.001]';