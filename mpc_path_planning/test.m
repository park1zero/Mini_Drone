x0=[0 0 0 0]';

% tic
% fprintf("기존 kinematics linear");
% conventional_mpc_test3(x0);
% toc
tic;
y= conventional_mpc([1 1 1 1 1 1 1 1 1 0 0 0]',20,10,10)
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