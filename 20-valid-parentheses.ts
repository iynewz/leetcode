function isValid(arrayS: string): boolean {
  const stack = [];
  const expect = { "(": ")", "[": "]", "{": "}" };

  for (let pointer = 0; pointer < arrayS.length; pointer++) {
    if (
      arrayS[pointer] == "(" ||
      arrayS[pointer] == "[" ||
      arrayS[pointer] == "{"
    ) {
      stack.push(arrayS[pointer]);
    } else if (
      stack.length > 0 &&
      expect[stack[stack.length - 1]] == arrayS[pointer]
    ) {
      stack.pop();
    } else return false;
  }
  return stack.length == 0;
}
