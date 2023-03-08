function [vx,vy]  = discrete_mpc(input,step)
tic
%DISCRETE_MPC 
% coder.extrinsic('quadprog');
%using drone dynamics
%result=[phi theta pi p q r u v w x y z];
Horizon =10; 
x=input(1:12);
x_d=input(12+Horizon);
y_d=input(12+2*Horizon);
z_d=-1.1;
dt=1;
 
desti=[0 0 0 0 0 0 0 0 0 x_d y_d z_d]';%destination
real_x=x(10);
real_y=x(11);
real_z=x(12);
dx=(x_d-real_x)/Horizon;
dy=(y_d-real_y)/Horizon;
dz=(z_d-real_z)/Horizon;



% reference making

desti_horizon=zeros(12*Horizon,1);
ref_const=zeros(12*Horizon,1);
for i=1:Horizon
    %    desti_horizon=[desti_horizon;[0 0 0 0 0 0 0 0 0 real_x+dx*i real_y+dy*i real_z+dz*i]'];
    desti_horizon(10+(i-1)*12)=real_x+dx*i;
    desti_horizon(11+(i-1)*12)=real_y+dy*i;
    desti_horizon(12+(i-1)*12)=real_z+dz*i;

%     desti_horizon=[desti_horizon;[0 0 0 0 0 0 0 0 0 real_x+dx*(i) real_y+dy*(i) real_z+dz*(i)]'];
    ref_const(10+(i-1)*12)=real_x+dx*i;
    ref_const(11+(i-1)*12)=real_y+dy*i;
    ref_const(12+(i-1)*12)=real_z+dz*i;
        
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
A_n=cell(20);
temp=Total_A;
for i = 1:20
    A_n{i}=temp;
    temp=temp*Total_A;
end


Gamma=zeros(60,12);
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

%% quadprog

%cost matrix
R=eye(16*Horizon);
R(13,13)=30;
R(14,14)=30;
R(15,15)=30;
R(16,16)=30;

Q=eye(12*Horizon);
Q(10,10)=10000;
Q(11,11)=10000;

        
for i=1:12
   Q(12*(Horizon-1)+i)=0;
end
        
H=R+modi_PI'*Q*modi_PI;

f=((x)'*Gamma'*Q*modi_PI-desti_horizon'*Q*modi_PI);
xmax=repmat(1000000000,12*Horizon,1);
xmin=repmat(-100000000,12*Horizon,1);
u_max=repmat([10,10,10,10,10,10,10,10,10,1000,1000,1000,1,5,5,5]',Horizon,1);
u_min=repmat(-[10,10,10,50,50,50,50,50,50,1000,1000,1000,1,.001,.001,0.0011]',Horizon,1);
%U=quadprog(H,f',[eye(320);-eye(320);PI;-PI],[u_max;-u_min;(xmax)-Gamma*(x); (-xmin)+Gamma*(x)]);

temp_PI=zeros(Horizon*12,Horizon*16);
temp_ref=zeros(12*Horizon,1);
epsilon_r=zeros(12*Horizon,1);
epsilon=[0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.04 0.04 0.001]';
for i=1:Horizon
    temp_PI(12*(i-1)+10,:)=modi_PI(12*(i-1)+10,:);
    temp_PI(12*(i-1)+11,:)=modi_PI(12*(i-1)+11,:);
    temp_PI(12*(i-1)+12,:)=modi_PI(12*(i-1)+12,:);


    temp_ref(12*(i-1)+10)=ref_const(12*(i-1)+10);
    temp_ref(12*(i-1)+11)=ref_const(12*(i-1)+11);
    temp_ref(12*(i-1)+12)=ref_const(12*(i-1)+12);

    
    epsilon_r(12*(i-1)+10)=epsilon(10); 
    epsilon_r(12*(i-1)+11)=epsilon(11); 
    epsilon_r(12*(i-1)+12)=epsilon(12); 

end
    

temp_x=[0 0 0 0 0 0 0 0 0 x(10) x(11) 0]';




opts = optimoptions('quadprog','Algorithm','active-set');
% opts = optimoptions(opts,'MaxIterations',1e4); % Recommended

x0=zeros(16*Horizon,1);

% for i=1:Horizon
%    x0(1+16*(i-1))=x_esti(1);
%    x0(2+16*(i-1))=x_esti(2);
%    x0(3+16*(i-1))=x_esti(3);
%    x0(4+16*(i-1))=x_esti(4);
%    x0(5+16*(i-1))=x_esti(5);
%    x0(6+16*(i-1))=x_esti(6);
%    x0(7+16*(i-1))=x_esti(7);
%    x0(8+16*(i-1))=x_esti(8);
%    x0(9+16*(i-1))=x_esti(9);
%    x0(10+16*(i-1))=x_esti(10);
%    x0(11+16*(i-1))=x_esti(11);
%    x0(12+16*(i-1))=x_esti(12);
%    x0(13+16*(i-1))=0;
%    x0(14+16*(i-1))=0;
%    x0(15+16*(i-1))=0;
%    x0(16+16*(i-1))=0;
% end
for i=1:Horizon
   x0(1+16*(i-1))=0;
   x0(2+16*(i-1))=0;
   x0(3+16*(i-1))=0;
   x0(4+16*(i-1))=0;
   x0(5+16*(i-1))=0;
   x0(6+16*(i-1))=0;
   x0(7+16*(i-1))=0;
   x0(8+16*(i-1))=0;
   x0(9+16*(i-1))=0;
   x0(10+16*(i-1))=0;
   x0(11+16*(i-1))=0;
   x0(12+16*(i-1))=0;
   x0(13+16*(i-1))=0;
   x0(14+16*(i-1))=0;
   x0(15+16*(i-1))=0;
   x0(16+16*(i-1))=0;
end
U=zeros(16*Horizon,1);
U=quadprog(H,f',[eye(16*Horizon);-eye(16*Horizon);temp_PI;-temp_PI],[u_max;-u_min;(temp_ref+epsilon_r)-Gamma*(temp_x); (-(temp_ref-epsilon_r))+Gamma*(temp_x)],[],[],[],[],zeros(16*Horizon,1),opts);
y=zeros(12*Horizon,1);
y=Gamma*x+modi_PI*U;
a=12*step+10;
b=12*step+11;
vx = y(a);
vy = y(b);

toc
end

