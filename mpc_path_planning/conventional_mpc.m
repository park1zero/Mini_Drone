function y= conventional_mpc(left_low,left_high,right_low,right_high)

dt=0.1;
prob = optimproblem('ObjectiveSense', 'min');
u0= optimvar('u0'); %%입력값
u1= optimvar('u1');
u2= optimvar('u2');
u3= optimvar('u3');
u4= optimvar('u4');

xy1= optimvar('x1', 2, 1); %%상태변수 
xy2= optimvar('x2', 2, 1);
xy3= optimvar('x3', 2, 1);
xy4= optimvar('x4', 2, 1);
xy5= optimvar('x5', 2, 1);

u=[u0 u1 u2 u3 u4];
xy=[xy1 xy2 xy3 xy4 xy5];


x_d=(left_high(1)+right_high(1))/2;
y_d=(left_high(2)+right_high(2))/2;




wgx=1;
wgy=1;
wa=1;
wy=1;
wk=1;
prob.Object=0;


for i=1:5
    x(i)=xy(4*(i-1)+1);
    y(i)=xy(4*(i-1)+2);
    theta(i)=xy(4*(i-1)+3);
    vel(i)=xy(4*(i-1)+4);

    v_acc(i)=u(2*(i-1)+1);
    w_acc(i)=u(2*(i-1)+2);

    prob.Object=prob.Object+wgx*(xy(x(i))-x_d)^2+wgy*(xy(y(i)).(2)-y_d)+wa*abs(v_acc(i))^2+wy*wk^2;



    f=[vel(i)*cos(theta(i)) vel(i)*sin(theta(i)) w_acc v_acc]';
    const(i)=x(i+1)==x(i)+f*dt;
end


%% state space 

x1=left_low(1);
x2=left_high(1);
x3=right_low(1);
x4=right_high(1);

y1=left_low(2);
y2=left_high(2);
y3=right_low(2);
y4=right_high(2);



const1 = x1 == A*x0 + B*u0;
const2 = x2 == A*x1 + B*u1;
const3 = x3 == A*x2 + B*u2;
const4 = x4 == A*x3 + B*u3;
const5 = x5 <= A*x4 + B*u4;
prob.Constraints.const1=const(1);
prob.Constraints.const2=const(2);
prob.Constraints.const3=const(3);
prob.Constraints.const4=const(4);
prob.Constraints.const5=const(5);

% %% terminal set
% FF=[0 1/8; 1/8 0; 0 -1/8; -1/8 0; 0 0; 0 0];
% GG=[0 0 0 0 1 -1]';
% LL = FF+GG*K;
% PHI = (A +B*K);
% LL=FF+GG*K;
% constT1 = LL*(PHI^0)*x5<=[1; 1;1; 1;1; 1;];
% constT2 = LL*(PHI^1)*x5<=[1; 1;1; 1;1; 1;];
% constT3 = LL*(PHI^2)*x5<=[1; 1;1; 1;1; 1;];
% constT4 = LL*(PHI^3)*x5<=[1; 1;1; 1;1; 1;];
% prob.Constraints.consT1=constT1;
% prob.Constraints.consT2=constT2;
% prob.Constraints.consT3=constT3;
% prob.Constraints.consT4=constT4;


%% QP
[result, feval] = solve(prob)

y = result;

end