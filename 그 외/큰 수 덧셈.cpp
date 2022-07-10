string add(string A, string B) {
	int sum = 0;
	string result;
	while (!A.empty() || !B.empty() || sum) {
		if (!A.empty()) {
			sum += A.back() - '0';
			A.pop_back();
		}
		if (!B.empty()) {
			sum += B.back() - '0';
			B.pop_back();
		}
		result.push_back((sum % 10) + '0');
		sum /= 10;
	}
	reverse(result.begin(), result.end());
	return result;
}