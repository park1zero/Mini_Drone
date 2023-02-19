function [result] = discrete_mpc(x,x_d,y_d,z_d)
%DISCRETE_MPC 

%using drone dynamics
%result=[phi theta pi p q r u v w x y z];
Horizon =20;
dt=1;

desti=[0 0 0 0 0 0 0 0 0 x_d y_d z_d]';%destination
dx=x_d/Horizon;
dy=y_d/Horizon;
dz=z_d/Horizon;
desti_horizon=[];
for i=1:Horizon
    desti_horizon=[desti_horizon;[0 0 0 0 0 0 0 0 0 dx*i dy*i dz*i]'];
end

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

temp=Total_A;
for i = 1:Horizon
    A_n{i}=temp;
    temp=temp*Total_A;
end


Gamma=[];
for i =1:Horizon
    temp=A_n{i};
    Gamma=[Gamma;temp];
end


PI=[];

temp=Total_B;
for i = 1:Horizon
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

%% quadprog

%cost matrix
R=eye(320);
Q=eye(240);
for i=1:12
   Q(12*(Horizon-1)+i)=0;
end
        
H=R+PI'*Q*PI;

f=((x)'*Gamma'*Q*PI-desti_horizon'*Q*PI);
xmax=repmat(1000000000,240,1);
xmin=repmat(-100000000,240,1);
u_max=repmat([1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000]',20,1);
u_min=repmat(-[1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000]',20,1);
U=quadprog(H,f',[eye(320);-eye(320);PI;-PI],[u_max;-u_min;(xmax)-Gamma*(x); (-xmin)+Gamma*(x)]);

xn=Gamma*x+PI*U;
result=xn;
end

