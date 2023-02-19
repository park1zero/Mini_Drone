x0=[0 0 0 0]';

% tic
% fprintf("기존 kinematics linear");
% conventional_mpc_test3(x0);
% toc
tic;
y= discrete_mpc([0 0 0 0 0 0 0 0 0 0 0 0]',20,10,10);
%처음 3개의 step이 쓰레기로 나오는 상황
% 원점을 기준으로 평행이동을 시켜주는 작업 필요?
toc;
% tic
% fprintf("다른 kinematics linear");
% conventional_mpc_test2(x0);
% toc
% 
% tic
% fprintf("기존 kinematics nonlinear");
% conventional_mpc_test3(x0);
% toc

x=zeros(20,1);
yr=zeros(20,1);
for i=1:20
%    x(i)=[y(16*(i-1)+10)]; 
%    yr(i)=[y(16*(i-1)+11)];
    x(i)=[y(12*(i-1)+10)]; 
    yr(i)=[y(12*(i-1)+11)];
end
plot(x,yr,"*")