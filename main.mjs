#!/bin/usr/node

import jsdom from "jsdom";
import fs from "fs/promises";
import path from "path";
import iconv from 'iconv-lite';

const JSDOM = new jsdom.JSDOM();
const parser = new JSDOM.window.DOMParser();

/**
 * 
 * @param { string[] } args 
 */
async function main(args) {
    const outputDir = args[2];
    const processedFiles = args.slice(3);

    for (const filePath of processedFiles) {
        console.log(filePath);
        const fileContent = await fs.readFile(filePath, { encoding: "utf-8" });
        const dom = parser.parseFromString(fileContent, "text/html");

        const elements = [...dom.querySelectorAll("pre div.NormalFont")];
        const text = elements
            .map(element => element.textContent)
            .filter(t => t.includes("WinMain") && !t.includes("android_main"))
            .map(t => t.replace("int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )", "int main()"));

        await Promise.all(text.map(async (t, i) => {
            const outFile = path.join(outputDir, path.basename(filePath, ".html") + "." + i.toString() + ".cpp");
            const encoded = iconv.encode(t, "sjis");
            await fs.writeFile(outFile, encoded);
        }));
    }
}

main(process.argv);
