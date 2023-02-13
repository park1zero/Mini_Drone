x0=[0 0 0 0]';

tic
fprintf("기존 kinematics linear");
conventional_mpc_test3(x0);
toc

% tic
% fprintf("다른 kinematics linear");
% conventional_mpc_test2(x0);
% toc
% 
% tic
% fprintf("기존 kinematics nonlinear");
% conventional_mpc_test3(x0);
% toc