import React, { useState, useContext, createContext } from 'react';
import { createRoot } from 'react-dom/client';

const languages = ['JavaScript', 'Python'];

const LanguageIdxContext = createContext(0);
function App() {
  // implement Context here so can be used in child components
  const [languageIdx, setLanguageIdx] = useState(0);
  function handleLanguageIdxChange(newLanguageIdx) {
    setLanguageIdx(newLanguageIdx % languages.length);
  }
  return (
    <LanguageIdxContext.Provider value={languageIdx}>
      <MainSection handleLanguageIdxChange={handleLanguageIdxChange} />
    </LanguageIdxContext.Provider>
  );
}

function MainSection({ handleLanguageIdxChange }) {
  const languageIdx = useContext(LanguageIdxContext);
  return (
    <div>
      <p id='favoriteLanguage'>
        Favorite programing language: {languages[languageIdx]}{' '}
      </p>
      <button
        id='changeFavorite'
        onClick={() => handleLanguageIdxChange(languageIdx + 1)}
      >
        Toggle language
      </button>
    </div>
  );
}

const container = document.getElementById('root');
const root = createRoot(container);
root.render(<App />);
