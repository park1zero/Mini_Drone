function y= conventional_mpc_test(x0)%,left_low,left_high,right_low,right_high)
%test 중인 mpc 입니다.


% if sw==0
% x0=zeros(4,1);
% x0=[.5;.5;.5;.5];
% end
x_d=10;
y_d=1;


dt=0.1;
u0= optimvar('u0',2,1); %%입력값
u1= optimvar('u1',2,1);
u2= optimvar('u2',2,1);
u3= optimvar('u3',2,1);
u4= optimvar('u4',2,1);

xy1= optimvar('x1', 4, 1); %%상태변수 
xy2= optimvar('x2', 4, 1);
xy3= optimvar('x3', 4, 1);
xy4= optimvar('x4', 4, 1);
xy5= optimvar('x5', 4, 1);

u=[u0 u1 u2 u3 u4];
xy=[x0 xy1 xy2 xy3 xy4 xy5];

prob = optimproblem('ObjectiveSense','minimize');

% x_d=(left_high(1)+right_high(1))/2;
% y_d=(left_high(2)+right_high(2))/2;

wgx=1;
wgy=1;
wa=1;
wy=1;
wk=1;


% x=zeros(6,1);
% y=zeros(6,1);
% theta=zeros(6,1);
% vel=zeros(6,1);
% a=zeros(5,1);


x(1)=xy(1);
y(1)=xy(2);
theta(1)=xy(3);
vel(1)=xy(4);

for i=1:5
    x(i+1)=xy(4*(i)+1);
    y(i+1)=xy(4*(i)+2);
    theta(i+1)=xy(4*(i)+3);
    vel(i+1)=xy(4*(i)+4);

%     v_acc(i)=u(2*(i-1)+1);
%     w_acc(i)=u(2*(i-1)+2);

    
    %a(i)=wgx*(x(i+1)-x_d)^2+wgy*(y(i+1)-y_d)^2;%+wa*(v_acc(i))^2;%+wy*wk^2;
    
    A=eye(2);
    a(i)=[x(i+1)-x_d;y(i+1)-y_d]'*A*[x(i+1)-x_d;y(i+1)-y_d];

    
    
%     f=[vel(i)*cos(theta(i)) vel(i)*sin(theta(i)) w_acc(i) v_acc(i)]';
    A=[1 0 -vel(i)*sin(theta(i))*dt cos(theta(i))*dt; 0 1 vel(i)*cos(theta(i))*dt sin(theta(i))*dt; 0 0 1 0;0 0 0 1];
    B=[0 0; 0 0; 0 1*dt; 1*dt 0];

    if i==1
%     prob.Constraints.const1=xy1==x0+f.*dt;
    prob.Constraints.const1=xy1==A*x0+B*u0;
    elseif i==2
%     prob.Constraints.const2=xy2==xy1+f.*dt;
    prob.Constraints.const2=xy2==A*xy1+B*u1;
    elseif i==3
%     prob.Constraints.const3=xy3==xy2+f.*dt;
    prob.Constraints.const3=xy3==A*xy2+B*u2;
    elseif i==4
%     prob.Constraints.const4=xy4==xy3+f.*dt;
    prob.Constraints.const4=xy4==A*xy3+B*u3;
    elseif i==5
%     prob.Constraints.const5=xy5==xy4+f.*dt;
    prob.Constraints.const5=xy5==xy4+B*u4;
    end
end

prob.Constraints.const6=xy1(4)<=3;
prob.Constraints.const7=xy2(4)<=3;


prob.Objective=a(1)+a(2)+a(3)+a(4)+a(5);

%% state space 
% 
% x1=left_low(1);
% x2=left_high(1);
% x3=right_low(1);
% x4=right_high(1);
% 
% y1=left_low(2);
% y2=left_high(2);
% y3=right_low(2);
% y4=right_high(2);


% prob.Constraints.const1=const(1);
% prob.Constraints.const2=const(2);
% prob.Constraints.const3=const(3);
% prob.Constraints.const4=const(4);
% prob.Constraints.const5=const(5);



%% QP
str.x0=x0;
str.x1=zeros(4,1);
str.x2=zeros(4,1);
str.x3=zeros(4,1);
str.x4=zeros(4,1);
str.x5=zeros(4,1);
str.u0=zeros(2,1);
str.u1=zeros(2,1);
str.u2=zeros(2,1);
str.u3=zeros(2,1);
str.u4=zeros(2,1);

opts=optimoptions("fmincon",Display="none");

[result,fval,exitflag,output,lambda] = solve(prob,str,Options=opts);
y=result.x1
end