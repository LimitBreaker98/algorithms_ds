/*
* Note for evaluators: It's 5:05 pm local time, will take a break to eat something.
* Thanks for understanding! 
* 5:48 pm, I'm back :).

*
* Solution assumes that the pattern on the right hand side is valid.
* i.e: {N}++ is not valid, as {N} is not after an *
* Solution assumes that the alphabetical characters come from an alphabet
* where letters use different cases (lower and upper).
*/

/*
 * Possible Tokens and meaning
 * + -> Single alphabetic character
 * * -> Three times a character
 * *{N} -> N times a character, where N >= 1
 */

// constants to represent the types ALPHABETIC and ANY, for character verification.
ALPHABETICAL = 'alphabetic';
ANY = 'any';

/*
 * Idea:
 * Let's call the string on the left "pattern" and the string on the right "text".
 * Let's also have an index of the current char in pattern and an index of the
 * current char in text. Call them: patternIdx, textIdx.
 * Now, process both the pattern and the text from left to right, by using the indices above.
 *
 * First, move the patternIdx until we have found a meaningful subpattern.
 * Then, attempt to move the textIdx according to what the meaningful subpattern tells us.
 *   If at some point the rule of the meaningul pattern is broken, return false.
 *
 * Repeat the steps above until we reach the end of the pattern and the text.
 * If both pointers are at the end, return true. Otherwise, the pattern also didn't match the text and return false.
 */

/*
 * This function takes the whole pattern and our current startPatternIdx
 * The function matches the current subpattern starting at startPatternIdx
 * And returns an object with the following keys:
 * charsOnText, a number that represents how many equal characters to read from text.
 * nextStartPatternIdx, the next candidate starting point to form a new pattern.
 * type: Either ALPHABETIC or ANY, which specifies the nature of the character(s) to verify
 */
function getMeaningfulSubpattern(pattern, startPatternIdx) {
  let currChar = pattern[startPatternIdx];
  let nextChar =
    startPatternIdx + 1 < pattern.length ? pattern[startPatternIdx + 1] : null;
  let nextNextChar =
    startPatternIdx + 2 < pattern.length ? pattern[startPatternIdx + 2] : null;
  //console.log(currChar, nextChar, nextNextChar)
  if (currChar === '+') {
    return {
      charsOnText: 1,
      nextStartPatternIdx: startPatternIdx + 1,
      type: ALPHABETICAL,
    };
  } else {
    if (nextChar === '{') {
      return {
        charsOnText: Number(nextNextChar),
        nextStartPatternIdx: startPatternIdx + 4,
        type: ANY,
      };
    } else {
      return {
        charsOnText: 3,
        nextStartPatternIdx: startPatternIdx + 1,
        type: ANY,
      };
    }
  }
}

/*
 * This function takes a number of charsOnText, the complete text, and the current textIdx
 * The function verifies that there is a sequence of equal characters of length charsOnText
 * starting from textIdx in the text.
 * And returns an object with the following keys:
 * verified: true or false depending on if the rules are met
 * nextTextIdx: The next starting character to match in the text, when a new pattern is processed.
 * Note that nextTextIdx is not returned when verified is false, as at that point we know that
 * the pattern did not match the text.
 */
function verifyCharsOnText(charsOnText, text, textIdx, type) {
  let baseChar = text[textIdx];
  textIdx++;
  charsOnText--;
  while (charsOnText > 0) {
    let currChar = textIdx < text.length ? text[textIdx] : null;
    if (baseChar !== currChar) {
      return { verified: false };
    }
    charsOnText--;
    textIdx++;
  }
  if (
    type === ALPHABETICAL &&
    baseChar.toLowerCase() === baseChar.toUpperCase()
  ) {
    return { verified: false };
  }
  return { verified: true, nextTextIdx: textIdx };
}

function WildcardCharacters(str) {
  [pattern, text] = str.split(' ');
  let startPatternIdx = 0;
  let textIdx = 0;
  while (startPatternIdx < pattern.length) {
    const { charsOnText, nextStartPatternIdx, type } = getMeaningfulSubpattern(
      pattern,
      startPatternIdx
    );
    if (textIdx >= text.length) {
      // Text ran out of chars but the pattern requires more chars
      return false;
    }
    const { verified, nextTextIdx } = verifyCharsOnText(
      charsOnText,
      text,
      textIdx,
      type
    );
    startPatternIdx = nextStartPatternIdx;
    textIdx = nextTextIdx;
    if (!verified) {
      return false;
    }
  }
  let validated = textIdx === text.length && startPatternIdx === pattern.length;
  return validated;
}

// keep this function call here
console.log(WildcardCharacters(readline()));
