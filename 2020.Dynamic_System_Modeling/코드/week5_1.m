gasprices = readtable("../데이터/gasprices.xlsx", "Range", "A5:K24");

Year = gasprices.Year;

Au = gasprices.Australia;
Ge = gasprices.Germany;
Me = gasprices.Mexico;
US = gasprices.USA;

avg = mean(Au(~isnan(Au))); %nan 이 아닌것들의 평균 
Au(isnan(Au)) = avg;

% indexing 
% linear , *Row column , **Logical
gasprices.France > gasprices.Germany;

any(gasprices.France > gasprices.Germany)   %% 1개라도 해당되는것이 있는지
any(gasprices.France(13:end) > gasprices.Germany(13:end))   %% 1개라도 해당되는것이 있는지
all(gasprices.France > gasprices.Germany)       %% 모든값이 다 해당?
all(gasprices.France(1:12) > gasprices.Germany(1:12))       %% 모든값이 다 해당?

%%
'Sejong' == 'sejong'        % 한글자 씩 비교

strcmp('Sejong' ,'sejong')  % 문자열 구분 (대소문자 구분)
strcmpi('Sejong' ,'sejong') % 대소문자 구분 x

%%

nnz(gasprices.France > gasprices.Germany)  % 몇개가 1인지 참인갯수반환









