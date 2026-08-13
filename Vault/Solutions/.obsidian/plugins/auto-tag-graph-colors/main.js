/*
THIS IS A GENERATED/COMPILED FILE AND SHOULD NOT BE EDITED DIRECTLY!
See the source files under src/ for the plugin source code.
*/

"use strict";
var __defProp = Object.defineProperty;
var __getOwnPropDesc = Object.getOwnPropertyDescriptor;
var __getOwnPropNames = Object.getOwnPropertyNames;
var __hasOwnProp = Object.prototype.hasOwnProperty;
var __export = (target, all) => {
  for (var name in all)
    __defProp(target, name, { get: all[name], enumerable: true });
};
var __copyProps = (to, from, except, desc) => {
  if (from && typeof from === "object" || typeof from === "function") {
    for (let key of __getOwnPropNames(from))
      if (!__hasOwnProp.call(to, key) && key !== except)
        __defProp(to, key, { get: () => from[key], enumerable: !(desc = __getOwnPropDesc(from, key)) || desc.enumerable });
  }
  return to;
};
var __toCommonJS = (mod) => __copyProps(__defProp({}, "__esModule", { value: true }), mod);

// src/main.ts
var main_exports = {};
__export(main_exports, {
  default: () => AutoTagGraphColorsPlugin
});
module.exports = __toCommonJS(main_exports);
var import_obsidian3 = require("obsidian");

// src/types.ts
var DEFAULT_SETTINGS = {
  enabled: true,
  colorMode: "primary",
  subtagMode: "separate",
  palette: "modern",
  saturation: 65,
  lightness: 55,
  excludedTags: [],
  priorityTags: [],
  tagColors: {},
  lockedColors: {},
  autoRefresh: true,
  ignoreSingleUseTags: false,
  showLegend: true,
  legendVisible: false,
  lastScanTime: 0,
  managedQueries: [],
  heatColoringEnabled: false,
  heatColdColor: "#4A90D9",
  heatHotColor: "#E74C3C",
  blendTagsEnabled: false,
  blendMonochromeEnabled: false,
  blendMonochromeHue: "#4A90D9"
};

// src/tag-scanner.ts
var TagScanner = class {
  constructor(app) {
    this.app = app;
  }
  /**
   * Scan every Markdown file in the vault and return a map of
   * normalised-tag → note-count.
   *
   * Uses MetadataCache exclusively — no disk reads.
   */
  scanAllTags() {
    var _a;
    const counts = /* @__PURE__ */ new Map();
    for (const file of this.app.vault.getMarkdownFiles()) {
      for (const tag of this.getTagsForFile(file)) {
        counts.set(tag, ((_a = counts.get(tag)) != null ? _a : 0) + 1);
      }
    }
    return counts;
  }
  /**
   * Return the deduplicated, normalised tag list for a single file.
   * Sources: frontmatter `tags` / `tag` field, and inline #tags.
   */
  getTagsForFile(file) {
    var _a, _b;
    const cache = this.app.metadataCache.getFileCache(file);
    if (!cache)
      return [];
    const tags = /* @__PURE__ */ new Set();
    const fmTags = (_a = cache.frontmatter) == null ? void 0 : _a["tags"];
    if (Array.isArray(fmTags)) {
      for (const t of fmTags) {
        if (typeof t === "string" && t.trim()) {
          tags.add(this.normalise(t.trim()));
        }
      }
    } else if (typeof fmTags === "string") {
      for (const t of fmTags.split(/[\s,]+/)) {
        if (t.trim())
          tags.add(this.normalise(t.trim()));
      }
    }
    const fmTag = (_b = cache.frontmatter) == null ? void 0 : _b["tag"];
    if (typeof fmTag === "string" && fmTag.trim()) {
      tags.add(this.normalise(fmTag.trim()));
    }
    if (cache.tags) {
      for (const entry of cache.tags) {
        tags.add(this.normalise(entry.tag));
      }
    }
    return Array.from(tags).filter((t) => t.length > 1);
  }
  /** Normalise to lowercase with a leading # */
  normalise(raw) {
    const stripped = raw.startsWith("#") ? raw : `#${raw}`;
    return stripped.toLowerCase();
  }
  /** filePath → deduplicated normalised tag list, for every markdown file that has tags. */
  getAllFileTags() {
    const out = /* @__PURE__ */ new Map();
    for (const file of this.app.vault.getMarkdownFiles()) {
      const tags = this.getTagsForFile(file);
      if (tags.length > 0)
        out.set(file.path, tags);
    }
    return out;
  }
};

// src/color-manager.ts
var PALETTES = {
  modern: [
    "#6C5CE7",
    "#00B894",
    "#0984E3",
    "#00CEC9",
    "#FDCB6E",
    "#E17055",
    "#FD79A8",
    "#A29BFE",
    "#55EFC4",
    "#74B9FF",
    "#FF7675",
    "#D63031",
    "#8E44AD",
    "#16A085",
    "#2980B9",
    "#F39C12",
    "#27AE60",
    "#C0392B",
    "#E84393",
    "#00897B"
  ],
  pastel: [
    "#C9C0F9",
    "#A8E6D5",
    "#B3D5F0",
    "#A8E4E4",
    "#FDEAB7",
    "#F5CBBD",
    "#FEBDD6",
    "#D5D0FC",
    "#A8F0DE",
    "#C5E0FC",
    "#FFBABA",
    "#B0EAEA",
    "#FEFAC8",
    "#F8C8D8",
    "#D5C5E6",
    "#E8C8F0",
    "#C8E8A8",
    "#F0D8C8",
    "#C8D0F8",
    "#E8F0C8"
  ],
  "high-contrast": [
    "#7B00FF",
    "#00CC44",
    "#0077FF",
    "#00CCCC",
    "#FFB300",
    "#FF4400",
    "#FF0088",
    "#8855FF",
    "#00FF99",
    "#3399FF",
    "#FF3333",
    "#00FFFF",
    "#FFE000",
    "#FF8800",
    "#AA00FF",
    "#FF0055",
    "#0055FF",
    "#00FF44",
    "#FF6600",
    "#CC00CC"
  ],
  "dark-optimized": [
    "#9B89FF",
    "#20D8A0",
    "#2BB5FF",
    "#1DDDDD",
    "#FFD166",
    "#FF8C6B",
    "#FF91C1",
    "#B8AAFF",
    "#6FFFD3",
    "#7FC5FF",
    "#FF8585",
    "#6EF7F7",
    "#FFEF85",
    "#FFA85C",
    "#C87AFF",
    "#FF6B9D",
    "#6B96FF",
    "#5BFFA0",
    "#FFA040",
    "#E060EE"
  ],
  /** Wong (2011) colorblind-safe palette + extensions */
  colorblind: [
    "#E69F00",
    "#56B4E9",
    "#009E73",
    "#F0E442",
    "#0072B2",
    "#D55E00",
    "#CC79A7",
    "#44AA99",
    "#882255",
    "#117733",
    "#332288",
    "#DDCC77",
    "#88CCEE",
    "#AA4499",
    "#999933",
    "#6699CC",
    "#661100",
    "#AA7744",
    "#4477AA",
    "#228833"
  ]
};
var GOLDEN_ANGLE = 137.50776405003785;
function djb2Hash(str) {
  let hash = 5381;
  for (let i = 0; i < str.length; i++) {
    hash = (hash << 5) + hash ^ str.charCodeAt(i);
    hash = hash >>> 0;
  }
  return hash;
}
function hslToHex(h, s, l) {
  const sn = s / 100;
  const ln = l / 100;
  const a = sn * Math.min(ln, 1 - ln);
  const f = (n) => {
    const k = (n + h / 30) % 12;
    const color = ln - a * Math.max(Math.min(k - 3, 9 - k, 1), -1);
    return Math.round(255 * color).toString(16).padStart(2, "0");
  };
  return `#${f(0)}${f(8)}${f(4)}`;
}
function perceptualDistance(hex1, hex2) {
  const parse = (h) => [
    parseInt(h.slice(1, 3), 16),
    parseInt(h.slice(3, 5), 16),
    parseInt(h.slice(5, 7), 16)
  ];
  const [r1, g1, b1] = parse(hex1);
  const [r2, g2, b2] = parse(hex2);
  return Math.sqrt(
    (r1 - r2) ** 2 * 0.299 + (g1 - g2) ** 2 * 0.587 + (b1 - b2) ** 2 * 0.114
  );
}
var ColorManager = class {
  constructor(settings) {
    this.settings = settings;
  }
  updateSettings(settings) {
    this.settings = settings;
  }
  /**
   * Generate (or retrieve from palette) a colour for a tag.
   *
   * @param tag           Tag string (with or without leading #)
   * @param existingColors Already-assigned hex colours (for contrast optimisation)
   */
  generateColorForTag(tag, existingColors = []) {
    const key = tag.replace(/^#/, "").toLowerCase();
    if (this.settings.palette === "hsl") {
      return this.generateHSLColor(key);
    }
    return this.generatePaletteColor(key, existingColors);
  }
  generateHSLColor(key) {
    const hash = djb2Hash(key);
    const index = hash % 360;
    const hue = index * GOLDEN_ANGLE % 360;
    return hslToHex(hue, this.settings.saturation, this.settings.lightness);
  }
  generatePaletteColor(key, existingColors) {
    const palette = PALETTES[this.settings.palette];
    const hash = djb2Hash(key);
    const startIndex = hash % palette.length;
    if (existingColors.length === 0) {
      return palette[startIndex];
    }
    let bestColor = palette[startIndex];
    let bestMinDist = -1;
    for (let i = 0; i < palette.length; i++) {
      const candidate = palette[(startIndex + i) % palette.length];
      const minDist = existingColors.reduce(
        (min, ec) => Math.min(min, perceptualDistance(candidate, ec)),
        Infinity
      );
      if (minDist > bestMinDist) {
        bestMinDist = minDist;
        bestColor = candidate;
      }
    }
    return bestColor;
  }
  /**
   * Produce a slightly lighter/different shade of a parent colour for subtags.
   * depth=1 → one level below parent, depth=2 → two levels, etc.
   */
  generateChildColor(parentColor, depth) {
    const r = parseInt(parentColor.slice(1, 3), 16);
    const g = parseInt(parentColor.slice(3, 5), 16);
    const b = parseInt(parentColor.slice(5, 7), 16);
    const blend = Math.min(depth * 0.12, 0.45);
    const lr = Math.round(r + (255 - r) * blend);
    const lg = Math.round(g + (255 - g) * blend);
    const lb = Math.round(b + (255 - b) * blend);
    return `#${lr.toString(16).padStart(2, "0")}${lg.toString(16).padStart(2, "0")}${lb.toString(16).padStart(2, "0")}`;
  }
  /** Returns the parent tag string (without #), or null if top-level. */
  getParentTag(tag) {
    const clean = tag.replace(/^#/, "");
    const idx = clean.lastIndexOf("/");
    return idx === -1 ? null : clean.substring(0, idx);
  }
  /** Returns nesting depth: #foo → 0, #foo/bar → 1, #foo/bar/baz → 2 */
  getTagDepth(tag) {
    var _a;
    return ((_a = tag.replace(/^#/, "").match(/\//g)) != null ? _a : []).length;
  }
  // ── Static utilities shared by graph-integration ──────────
  static hexToRgbInt(hex) {
    const clean = hex.replace("#", "");
    const r = parseInt(clean.substring(0, 2), 16);
    const g = parseInt(clean.substring(2, 4), 16);
    const b = parseInt(clean.substring(4, 6), 16);
    return (r & 255) << 16 | (g & 255) << 8 | b & 255;
  }
  static rgbIntToHex(rgb) {
    const r = rgb >> 16 & 255;
    const g = rgb >> 8 & 255;
    const b = rgb & 255;
    return "#" + [r, g, b].map((v) => v.toString(16).padStart(2, "0")).join("");
  }
};

// src/graph-integration.ts
var import_obsidian = require("obsidian");
function hexToRgbTuple(hex) {
  const c = hex.replace("#", "");
  return [
    parseInt(c.substring(0, 2), 16),
    parseInt(c.substring(2, 4), 16),
    parseInt(c.substring(4, 6), 16)
  ];
}
function rgbToHsl(r, g, b) {
  r /= 255;
  g /= 255;
  b /= 255;
  const max = Math.max(r, g, b), min = Math.min(r, g, b);
  const l = (max + min) / 2;
  let h = 0, s = 0;
  if (max !== min) {
    const d = max - min;
    s = l > 0.5 ? d / (2 - max - min) : d / (max + min);
    switch (max) {
      case r:
        h = (g - b) / d + (g < b ? 6 : 0);
        break;
      case g:
        h = (b - r) / d + 2;
        break;
      case b:
        h = (r - g) / d + 4;
        break;
    }
    h *= 60;
  }
  return [h, s, l];
}
function hslToHex2(h, s, l) {
  h = (h % 360 + 360) % 360;
  const c = (1 - Math.abs(2 * l - 1)) * s;
  const x = c * (1 - Math.abs(h / 60 % 2 - 1));
  const m = l - c / 2;
  let r = 0, g = 0, b = 0;
  if (h < 60) {
    r = c;
    g = x;
    b = 0;
  } else if (h < 120) {
    r = x;
    g = c;
    b = 0;
  } else if (h < 180) {
    r = 0;
    g = c;
    b = x;
  } else if (h < 240) {
    r = 0;
    g = x;
    b = c;
  } else if (h < 300) {
    r = x;
    g = 0;
    b = c;
  } else {
    r = c;
    g = 0;
    b = x;
  }
  const to = (v) => Math.round((v + m) * 255).toString(16).padStart(2, "0");
  return "#" + to(r) + to(g) + to(b);
}
function interpolateColor(t, coldHex, hotHex) {
  const [cr, cg, cb] = hexToRgbTuple(coldHex);
  const [hr, hg, hb] = hexToRgbTuple(hotHex);
  const [h1, s1, l1] = rgbToHsl(cr, cg, cb);
  const [h2, s2, l2] = rgbToHsl(hr, hg, hb);
  const directDelta = h2 - h1;
  const wrapDelta = directDelta > 0 ? directDelta - 360 : directDelta + 360;
  const midDirect = ((h1 + directDelta / 2) % 360 + 360) % 360;
  const useWrap = midDirect > 60 && midDirect < 180;
  const delta = useWrap ? wrapDelta : directDelta;
  const h = h1 + delta * t;
  const s = s1 + (s2 - s1) * t;
  const l = l1 + (l2 - l1) * t;
  return hslToHex2(h, s, l);
}
function getInternalPlugins(app) {
  return app.internalPlugins;
}
function getGraphPlugin(app) {
  var _a, _b;
  return (_b = (_a = getInternalPlugins(app)) == null ? void 0 : _a.plugins) == null ? void 0 : _b["graph"];
}
function getConfigDir(app) {
  return app.vault.configDir;
}
var GraphIntegration = class {
  constructor(app, settings) {
    this.legendByContainer = /* @__PURE__ */ new WeakMap();
    this.allLegends = /* @__PURE__ */ new Set();
    this.app = app;
    this.settings = settings;
  }
  updateSettings(settings) {
    this.settings = settings;
  }
  /**
   * Compute the colour that will actually be painted on the graph for a note
   * tagged with ONLY this one tag, respecting the current mode (blend/mono).
   * Used by the legend and settings tag list so they mirror the graph output.
   */
  getDisplayColorForTag(tag, baseHex) {
    if (!this.settings.blendTagsEnabled)
      return baseHex;
    const sortedKey = tag;
    let hash = 0;
    for (let i = 0; i < sortedKey.length; i++) {
      hash = (hash << 5) - hash + sortedKey.charCodeAt(i);
      hash |= 0;
    }
    if (this.settings.blendMonochromeEnabled) {
      const [mr, mg, mb] = hexToRgbTuple(this.settings.blendMonochromeHue);
      const [monoH, monoS] = rgbToHsl(mr, mg, mb);
      const hVary = (Math.abs(hash >> 6) % 600 - 300) / 10;
      const lVary2 = (Math.abs(hash) % 500 - 250) / 1e3;
      const sVary = (Math.abs(hash >> 3) % 300 - 150) / 1e3;
      const h2 = ((monoH + hVary) % 360 + 360) % 360;
      const l2 = Math.min(0.8, Math.max(0.25, 0.55 + lVary2));
      const s2 = Math.min(1, Math.max(0.2, monoS + sVary));
      return hslToHex2(h2, s2, l2);
    }
    const [br, bg, bb] = hexToRgbTuple(baseHex);
    let [h, s, l] = rgbToHsl(br, bg, bb);
    const lVary = (Math.abs(hash) % 200 - 100) / 1e3;
    l = Math.min(0.85, Math.max(0.3, l + lVary));
    return hslToHex2(h, s, l);
  }
  // ── Colour application ────────────────────────────────────
  async applyColors(tagColors, priorityTags, colorMode, managedQueries, fileTags) {
    const tagGroups = this.settings.blendTagsEnabled && fileTags ? this.buildBlendedGroups(fileTags, tagColors, priorityTags) : this.buildColorGroups(tagColors, priorityTags, colorMode);
    const heatGroups = this.settings.heatColoringEnabled ? this.computeHeatGroups() : [];
    const allGroups = [...heatGroups, ...tagGroups];
    await this.writeGraphJson(allGroups, managedQueries);
    this.updateInternalMemory(allGroups, managedQueries);
    this.applyToDataEngines(allGroups, managedQueries);
    return allGroups.map((g) => g.query);
  }
  /**
   * Remove every color-group this plugin has ever created (identified via
   * `managedQueries`) from graph.json, from the internal plugin memory, and
   * from every open graph view. Leaves user-added groups untouched.
   */
  async clearManagedGroups(managedQueries) {
    var _a, _b, _c, _d;
    const managed = new Set(managedQueries);
    try {
      const configDir = getConfigDir(this.app);
      const graphPath = (0, import_obsidian.normalizePath)(`${configDir}/graph.json`);
      let current = {};
      try {
        current = JSON.parse(await this.app.vault.adapter.read(graphPath));
      } catch (e) {
      }
      current.colorGroups = ((_a = current.colorGroups) != null ? _a : []).filter((g) => !managed.has(g.query));
      await this.app.vault.adapter.write(graphPath, JSON.stringify(current, null, 2));
    } catch (e) {
      console.error("[ATGC] clearManagedGroups disk error:", e);
    }
    try {
      const gp = getGraphPlugin(this.app);
      const instance = gp == null ? void 0 : gp.instance;
      if ((_b = instance == null ? void 0 : instance.options) == null ? void 0 : _b.colorGroups) {
        instance.options.colorGroups = instance.options.colorGroups.filter((g) => !managed.has(g.query));
        if (typeof (gp == null ? void 0 : gp.saveData) === "function") {
          void gp.saveData(instance.options);
        }
      }
    } catch (e) {
      console.error("[ATGC] clearManagedGroups memory error:", e);
    }
    for (const leaf of this.app.workspace.getLeavesOfType("graph")) {
      try {
        const view = leaf.view;
        const de = view.dataEngine;
        if (!de || typeof de.setOptions !== "function")
          continue;
        const existing = (_d = (_c = de.options) == null ? void 0 : _c.colorGroups) != null ? _d : [];
        de.setOptions({ colorGroups: existing.filter((g) => !managed.has(g.query)) });
      } catch (e) {
        console.error("[ATGC] clearManagedGroups view error:", e);
      }
    }
  }
  /** Log graph internals to the developer console for debugging. */
  logDebugInfo() {
    const gp = getGraphPlugin(this.app);
    const leaves = this.app.workspace.getLeavesOfType("graph");
    console.info("[ATGC] graph plugin present:", !!gp, "| open graph leaves:", leaves.length);
  }
  // ── Tag colour groups ─────────────────────────────────────
  buildColorGroups(tagColors, priorityTags, colorMode) {
    const entries = Object.entries(tagColors);
    let sorted;
    if (colorMode === "priority" && priorityTags.length > 0) {
      const keys = priorityTags.map((t) => this.normaliseKey(t));
      const set = new Set(keys);
      const inP = entries.filter(([t]) => set.has(t)).sort(([a], [b]) => keys.indexOf(a) - keys.indexOf(b));
      sorted = [...inP, ...entries.filter(([t]) => !set.has(t))];
    } else {
      sorted = entries;
    }
    return sorted.map(([tag, hex]) => ({
      query: `tag:${tag.startsWith("#") ? tag : `#${tag}`}`,
      color: { a: 1, rgb: ColorManager.hexToRgbInt(hex) }
    }));
  }
  normaliseKey(t) {
    return (t.startsWith("#") ? t : `#${t}`).toLowerCase();
  }
  // ── Smart tag blending ────────────────────────────────────
  /**
   * Emit one color-group per note whose colour is:
   *   base   = primary tag colour (priority list first, else file's first tag)
   *   hue    = shifted 15% toward the average hue of secondary tags
   *   light. = varied ±10% deterministically per tag-combo hash
   * Notes with identical tag sets end up with identical colors.
   */
  buildBlendedGroups(fileTags, tagColors, priorityTags) {
    var _a;
    const priKeys = priorityTags.map((t) => this.normaliseKey(t));
    const groups = [];
    const mono = this.settings.blendMonochromeEnabled;
    const [mr, mg, mb] = hexToRgbTuple(this.settings.blendMonochromeHue);
    const [monoH, monoS] = rgbToHsl(mr, mg, mb);
    for (const [filePath, tagsRaw] of fileTags) {
      const tags = tagsRaw.filter((t) => tagColors[t]);
      if (tags.length === 0)
        continue;
      let primary = (_a = tags.find((t) => priKeys.includes(t))) != null ? _a : tags[0];
      let h, s, l;
      if (mono) {
        h = monoH;
        s = monoS;
        l = 0.55;
      } else {
        const baseHex = tagColors[primary];
        const [br, bg, bb] = hexToRgbTuple(baseHex);
        [h, s, l] = rgbToHsl(br, bg, bb);
        const others = tags.filter((t) => t !== primary);
        if (others.length > 0) {
          let acc = 0;
          for (const t of others) {
            const [r2, g2, b2] = hexToRgbTuple(tagColors[t]);
            const [h2] = rgbToHsl(r2, g2, b2);
            let delta = h2 - h;
            if (delta > 180)
              delta -= 360;
            if (delta < -180)
              delta += 360;
            acc += delta;
          }
          h += acc / others.length * 0.15;
        }
        s = Math.min(1, s + Math.min(0.15, (tags.length - 1) * 0.03));
      }
      const sortedKey = tags.slice().sort().join("|");
      let hash = 0;
      for (let i = 0; i < sortedKey.length; i++) {
        hash = (hash << 5) - hash + sortedKey.charCodeAt(i);
        hash |= 0;
      }
      if (mono) {
        const hVary = (Math.abs(hash >> 6) % 600 - 300) / 10;
        const lVary = (Math.abs(hash) % 500 - 250) / 1e3;
        const sVary = (Math.abs(hash >> 3) % 300 - 150) / 1e3;
        h = ((monoH + hVary) % 360 + 360) % 360;
        l = Math.min(0.8, Math.max(0.25, l + lVary));
        s = Math.min(1, Math.max(0.2, s + sVary));
      } else {
        const lVary = (Math.abs(hash) % 200 - 100) / 1e3;
        l = Math.min(0.85, Math.max(0.3, l + lVary));
      }
      const hex = hslToHex2(h, s, l);
      const safe = filePath.replace(/"/g, '\\"');
      groups.push({
        query: `path:"${safe}"`,
        color: { a: 1, rgb: ColorManager.hexToRgbInt(hex) }
      });
    }
    return groups;
  }
  // ── Heat coloring ─────────────────────────────────────────
  computeHeatGroups() {
    var _a, _b;
    const resolvedLinks = this.app.metadataCache.resolvedLinks;
    if (!resolvedLinks)
      return [];
    const counts = /* @__PURE__ */ new Map();
    for (const [from, links] of Object.entries(resolvedLinks)) {
      counts.set(from, ((_a = counts.get(from)) != null ? _a : 0) + Object.keys(links).length);
      for (const to of Object.keys(links)) {
        counts.set(to, ((_b = counts.get(to)) != null ? _b : 0) + 1);
      }
    }
    if (counts.size === 0)
      return [];
    const entries = Array.from(counts.entries()).sort((a, b) => a[1] - b[1]);
    const rankOf = /* @__PURE__ */ new Map();
    let currentRank = 0;
    let prevCount = Number.NEGATIVE_INFINITY;
    entries.forEach(([path, cnt], i) => {
      if (cnt !== prevCount) {
        currentRank = i;
        prevCount = cnt;
      }
      rankOf.set(path, currentRank);
    });
    const maxRank = Math.max(1, entries.length - 1);
    return entries.map(([filePath]) => {
      var _a2;
      const t = ((_a2 = rankOf.get(filePath)) != null ? _a2 : 0) / maxRank;
      const hex = interpolateColor(t, this.settings.heatColdColor, this.settings.heatHotColor);
      const safe = filePath.replace(/"/g, '\\"');
      return { query: `path:"${safe}"`, color: { a: 1, rgb: ColorManager.hexToRgbInt(hex) } };
    });
  }
  // ── Internal memory update ────────────────────────────────
  /**
   * Set colorGroups on the live options object and save via gp.saveData().
   * Returns true when gp.saveData was available and called.
   *
   * Confirmed via runtime debug:
   *   - instance.options EXISTS (showTags, search, etc.)
   *   - instance.save = undefined, instance.trigger = undefined
   *   - gp.saveData is the correct save method to check
   */
  updateInternalMemory(newGroups, managedQueries) {
    var _a;
    try {
      const gp = getGraphPlugin(this.app);
      const instance = gp == null ? void 0 : gp.instance;
      if (!(instance == null ? void 0 : instance.options)) {
        return false;
      }
      const prev = new Set(managedQueries);
      const inc = new Set(newGroups.map((g) => g.query));
      const existing = (_a = instance.options.colorGroups) != null ? _a : [];
      const preserved = existing.filter((g) => !prev.has(g.query) && !inc.has(g.query));
      instance.options.colorGroups = [...preserved, ...newGroups];
      if (typeof (gp == null ? void 0 : gp.saveData) === "function") {
        void gp.saveData(instance.options);
        return true;
      }
      return false;
    } catch (e) {
      console.error("[ATGC] updateInternalMemory error:", e);
      return false;
    }
  }
  // ── graph.json file-system fallback ──────────────────────
  async writeGraphJson(newGroups, managedQueries) {
    var _a;
    try {
      const configDir = getConfigDir(this.app);
      const graphPath = (0, import_obsidian.normalizePath)(`${configDir}/graph.json`);
      const prev = new Set(managedQueries);
      const inc = new Set(newGroups.map((g) => g.query));
      let current = {};
      try {
        current = JSON.parse(await this.app.vault.adapter.read(graphPath));
      } catch (e) {
      }
      const existing = (_a = current.colorGroups) != null ? _a : [];
      current.colorGroups = [
        ...existing.filter((g) => !prev.has(g.query) && !inc.has(g.query)),
        ...newGroups
      ];
      await this.app.vault.adapter.write(graphPath, JSON.stringify(current, null, 2));
    } catch (e) {
      console.error("[ATGC] writeGraphJson error:", e);
    }
  }
  // ── Graph view refresh ────────────────────────────────────
  /**
   * The ONLY confirmed working method to repaint graph nodes.
   * Calls view.dataEngine.setOptions({colorGroups}) on every open graph view.
   * Confirmed via runtime debug — dataEngine.setOptions is a real method
   * and it triggers the actual visual repaint.
   *
   * We merge with existing groups (preserving user-added ones not managed by us).
   */
  applyToDataEngines(newGroups, managedQueries) {
    var _a, _b;
    const prev = new Set(managedQueries);
    const inc = new Set(newGroups.map((g) => g.query));
    for (const leaf of this.app.workspace.getLeavesOfType("graph")) {
      try {
        const view = leaf.view;
        const de = view.dataEngine;
        if (!de || typeof de.setOptions !== "function") {
          continue;
        }
        const existing = (_b = (_a = de.options) == null ? void 0 : _a.colorGroups) != null ? _b : [];
        const preserved = existing.filter((g) => !prev.has(g.query) && !inc.has(g.query));
        de.setOptions({ colorGroups: [...preserved, ...newGroups] });
      } catch (e) {
        console.error("[ATGC] applyToDataEngines error:", e);
      }
    }
  }
  /**
   * onOptionsChange() confirmed present on graph view prototype.
   * It re-reads instance.options.colorGroups and repaints all nodes.
   * No setViewState — that was overwriting colorGroups.
   */
  callOnOptionsChange() {
    for (const leaf of this.app.workspace.getLeavesOfType("graph")) {
      try {
        const view = leaf.view;
        if (typeof view.onOptionsChange === "function") {
          view.onOptionsChange();
        }
      } catch (e) {
        console.error("[ATGC] callOnOptionsChange error:", e);
      }
    }
  }
  // ── Legend overlay ────────────────────────────────────────
  updateLegend(leaf, tagColors, tagCounts, onColorChange, onToggle) {
    const container = leaf.view.containerEl;
    const prev = this.legendByContainer.get(container);
    if (prev) {
      prev.remove();
      this.allLegends.delete(prev);
      this.legendByContainer.delete(container);
    }
    if (!this.settings.showLegend)
      return;
    const wrapper = this.buildLegend(tagColors, tagCounts, onColorChange, onToggle);
    container.appendChild(wrapper);
    this.legendByContainer.set(container, wrapper);
    this.allLegends.add(wrapper);
  }
  removeAllLegends() {
    this.allLegends.forEach((el) => el.remove());
    this.allLegends.clear();
  }
  buildLegend(tagColors, tagCounts, onColorChange, onToggle) {
    const wrapper = createDiv({ cls: "atgc-legend-wrapper" });
    const tagCount = Object.keys(tagColors).length;
    const toggleBtn = wrapper.createDiv({ cls: "atgc-legend-toggle-btn" });
    const svgNs = "http://www.w3.org/2000/svg";
    const svg = document.createElementNS(svgNs, "svg");
    svg.setAttribute("width", "13");
    svg.setAttribute("height", "13");
    svg.setAttribute("viewBox", "0 0 24 24");
    svg.setAttribute("fill", "none");
    svg.setAttribute("stroke", "currentColor");
    svg.setAttribute("stroke-width", "2.5");
    svg.setAttribute("stroke-linecap", "round");
    svg.setAttribute("stroke-linejoin", "round");
    const path = document.createElementNS(svgNs, "path");
    path.setAttribute("d", "M20.59 13.41l-7.17 7.17a2 2 0 0 1-2.83 0L2 12V2h10l8.59 8.59a2 2 0 0 1 0 2.82z");
    svg.appendChild(path);
    const circle = document.createElementNS(svgNs, "circle");
    circle.setAttribute("cx", "7");
    circle.setAttribute("cy", "7");
    circle.setAttribute("r", "1");
    circle.setAttribute("fill", "currentColor");
    svg.appendChild(circle);
    toggleBtn.appendChild(svg);
    toggleBtn.createSpan({ text: String(tagCount) });
    toggleBtn.setAttr("aria-label", "Tag colors");
    const panel = wrapper.createDiv({ cls: "atgc-legend-panel atgc-legend-panel-hidden" });
    const header = panel.createDiv({ cls: "atgc-legend-panel-header" });
    header.createSpan({ text: "Tag colors" });
    const closeBtn = header.createEl("button", { cls: "atgc-legend-close-btn", text: "\xD7" });
    const body = panel.createDiv({ cls: "atgc-legend-panel-body" });
    const sorted = Object.entries(tagColors).map(([tag, color]) => {
      var _a;
      return { tag, color, count: (_a = tagCounts.get(tag)) != null ? _a : 0 };
    }).sort((a, b) => b.count - a.count).slice(0, 30);
    for (const entry of sorted) {
      const { tag } = entry;
      let { color } = entry;
      color = this.getDisplayColorForTag(tag, color);
      entry.color = color;
      const item = body.createDiv({ cls: "atgc-legend-item" });
      const dot = item.createSpan({ cls: "atgc-legend-dot" });
      dot.style.backgroundColor = color;
      item.createSpan({ cls: "atgc-legend-label", text: tag.replace(/^#/, "") });
      item.createSpan({ cls: "atgc-legend-count", text: String(entry.count) });
      const picker = item.createEl("input", { cls: "atgc-legend-picker" });
      picker.type = "color";
      picker.value = color;
      picker.title = `Change color for ${tag}`;
      const stop = (e) => {
        e.stopPropagation();
      };
      ["click", "mousedown", "pointerdown", "focus"].forEach(
        (evt) => picker.addEventListener(evt, stop)
      );
      picker.addEventListener("input", (e) => {
        e.stopPropagation();
        color = picker.value;
        dot.style.backgroundColor = color;
        onColorChange(tag, color);
      });
      picker.addEventListener("change", (e) => {
        e.stopPropagation();
      });
    }
    const footer = panel.createDiv({ cls: "atgc-legend-footer" });
    footer.createSpan({ text: "by " });
    const brand = footer.createEl("a", {
      text: "Meetzy Corp FZCO",
      cls: "atgc-legend-brand",
      href: "https://meetzy.ai"
    });
    brand.setAttr("target", "_blank");
    brand.setAttr("rel", "noopener");
    brand.addEventListener("click", (e) => {
      e.stopPropagation();
    });
    const toggle = () => {
      const willOpen = panel.classList.contains("atgc-legend-panel-hidden");
      panel.classList.toggle("atgc-legend-panel-hidden", !willOpen);
      toggleBtn.classList.toggle("atgc-legend-toggle-active", willOpen);
      onToggle(willOpen);
    };
    toggleBtn.addEventListener("click", (e) => {
      e.stopPropagation();
      toggle();
    });
    closeBtn.addEventListener("click", (e) => {
      e.stopPropagation();
      toggle();
    });
    if (this.settings.legendVisible) {
      panel.classList.remove("atgc-legend-panel-hidden");
      toggleBtn.classList.add("atgc-legend-toggle-active");
    }
    return wrapper;
  }
};

// src/settings.ts
var import_obsidian2 = require("obsidian");
var AutoTagGraphSettingTab = class extends import_obsidian2.PluginSettingTab {
  constructor(app, plugin) {
    super(app, plugin);
    this.applyTimer = null;
    this.plugin = plugin;
  }
  /** Debounced full rescan + apply — for text inputs typed by the user. */
  scheduleRescan(delay = 400) {
    if (this.applyTimer !== null)
      window.clearTimeout(this.applyTimer);
    this.applyTimer = window.setTimeout(() => {
      void this.plugin.fullScanAndApply();
    }, delay);
  }
  /** Debounced re-apply of current colors (no rescan). */
  scheduleApply(delay = 200) {
    if (this.applyTimer !== null)
      window.clearTimeout(this.applyTimer);
    this.applyTimer = window.setTimeout(() => {
      void this.plugin.applyCurrentColors();
    }, delay);
  }
  display() {
    const { containerEl } = this;
    containerEl.empty();
    containerEl.addClass("atgc-settings");
    this.renderHeader(containerEl);
    this.renderGeneral(containerEl);
    this.renderScan(containerEl);
    this.renderColors(containerEl);
    this.renderDisplay(containerEl);
    this.renderTagList(containerEl);
    this.renderFooter(containerEl);
  }
  // ── Header ────────────────────────────────────────────────
  renderHeader(el) {
    const header = el.createDiv({ cls: "atgc-header" });
    header.createEl("p", {
      cls: "atgc-subtitle",
      text: "Automatically assign distinct, stable colors to every tag in your vault and paint them onto the graph view. Pick a palette, hit scan, and your knowledge graph becomes a color-coded map of your thinking."
    });
    const about = header.createDiv({ cls: "atgc-about" });
    const aboutText = about.createEl("p", { cls: "atgc-about-text" });
    aboutText.createSpan({ text: "A side project by " });
    const brand = aboutText.createEl("a", {
      text: "Meetzy",
      cls: "atgc-brand",
      href: "https://meetzy.ai"
    });
    brand.setAttr("target", "_blank");
    brand.setAttr("rel", "noopener");
    aboutText.createSpan({ text: " \u2014 an AI-native platform for marketing and sales teams." });
  }
  // ── Footer ────────────────────────────────────────────────
  renderFooter(el) {
    const footer = el.createDiv({ cls: "atgc-footer" });
    const line = footer.createEl("p", { cls: "atgc-footer-line" });
    line.createSpan({ text: "A side project by " });
    const brand = line.createEl("a", {
      text: "Meetzy Corp FZCO",
      cls: "atgc-brand",
      href: "https://meetzy.ai"
    });
    brand.setAttr("target", "_blank");
    brand.setAttr("rel", "noopener");
    line.createSpan({ text: "." });
  }
  // ── General ───────────────────────────────────────────────
  renderGeneral(el) {
    new import_obsidian2.Setting(el).setName("Enable plugin").setDesc("Toggle automatic tag coloring on or off. Turning it off removes every color group this plugin created from the graph view.").addToggle((t) => t.setValue(this.plugin.settings.enabled).onChange(async (val) => {
      var _a;
      this.plugin.settings.enabled = val;
      await this.plugin.saveSettings();
      if (val) {
        void this.plugin.fullScanAndApply();
      } else {
        await this.plugin.graphIntegration.clearManagedGroups((_a = this.plugin.settings.managedQueries) != null ? _a : []);
        this.plugin.settings.managedQueries = [];
        await this.plugin.saveSettings();
        this.plugin.graphIntegration.removeAllLegends();
      }
    }));
    new import_obsidian2.Setting(el).setName("Auto-refresh").setDesc("Re-scan and re-apply colors automatically when tags change.").addToggle((t) => t.setValue(this.plugin.settings.autoRefresh).onChange(async (val) => {
      this.plugin.settings.autoRefresh = val;
      await this.plugin.saveSettings();
    }));
  }
  // ── Scan actions ──────────────────────────────────────────
  renderScan(el) {
    new import_obsidian2.Setting(el).setName("Tag scanning").setHeading();
    new import_obsidian2.Setting(el).setName("Scan vault now").setDesc("Immediately scan all notes and apply colors to the graph view.").addButton((b) => b.setButtonText("Scan vault now").setCta().onClick(async () => {
      await this.plugin.fullScanAndApply();
      new import_obsidian2.Notice("Auto Tag Graph Colors: vault scanned and colors applied.");
      this.display();
    }));
    new import_obsidian2.Setting(el).setName("Regenerate all colors").setDesc("Re-generate colors for all unlocked tags (locked colors are preserved).").addButton((b) => b.setButtonText("Regenerate all colors").onClick(async () => {
      await this.plugin.regenerateAllColors();
      this.display();
    }));
    new import_obsidian2.Setting(el).setName("Reset all colors").setDesc("Delete every saved color and start from scratch.").addButton((b) => b.setButtonText("Reset all colors").setWarning().onClick(async () => {
      this.plugin.settings.tagColors = {};
      this.plugin.settings.lockedColors = {};
      await this.plugin.saveSettings();
      await this.plugin.fullScanAndApply();
      new import_obsidian2.Notice("Auto Tag Graph Colors: all colors reset.");
      this.display();
    }));
    new import_obsidian2.Setting(el).setName("Ignore single-use tags").setDesc("Do not assign a color to tags that appear in only one note.").addToggle((t) => t.setValue(this.plugin.settings.ignoreSingleUseTags).onChange(async (val) => {
      this.plugin.settings.ignoreSingleUseTags = val;
      await this.plugin.saveSettings();
      await this.plugin.fullScanAndApply();
    }));
    new import_obsidian2.Setting(el).setName("Excluded tags").setDesc("Comma-separated tags to never color, e.g. #daily, #template").addText((t) => t.setPlaceholder("#daily, #template, #archived").setValue(this.plugin.settings.excludedTags.join(", ")).onChange(async (val) => {
      this.plugin.settings.excludedTags = val.split(",").map((s) => s.trim().toLowerCase()).filter((s) => s.length > 0).map((s) => s.startsWith("#") ? s : `#${s}`);
      await this.plugin.saveSettings();
      this.scheduleRescan();
    }));
  }
  // ── Colour generation settings ────────────────────────────
  renderColors(el) {
    new import_obsidian2.Setting(el).setName("Color generation").setHeading();
    new import_obsidian2.Setting(el).setName("Color palette").setDesc("Choose the source palette for tag color assignment.").addDropdown((d) => d.addOption("modern", "Modern").addOption("pastel", "Pastel").addOption("high-contrast", "High Contrast").addOption("dark-optimized", "Dark Mode Optimised").addOption("colorblind", "Colorblind-Friendly (Wong 2011)").addOption("hsl", "HSL Generated (golden-angle)").setValue(this.plugin.settings.palette).onChange(async (val) => {
      this.plugin.settings.palette = val;
      await this.plugin.saveSettings();
      await this.plugin.regenerateAllColors();
      this.display();
    }));
    if (this.plugin.settings.palette === "hsl") {
      new import_obsidian2.Setting(el).setName("Saturation").setDesc("Color saturation for the HSL palette (0 = grey, 100 = vivid).").addSlider((s) => s.setLimits(0, 100, 5).setValue(this.plugin.settings.saturation).onChange(async (val) => {
        this.plugin.settings.saturation = val;
        await this.plugin.saveSettings();
        if (this.applyTimer !== null)
          window.clearTimeout(this.applyTimer);
        this.applyTimer = window.setTimeout(() => {
          void this.plugin.regenerateAllColors();
        }, 200);
      }));
      new import_obsidian2.Setting(el).setName("Lightness").setDesc("Color lightness for the HSL palette (0 = black, 100 = white).").addSlider((s) => s.setLimits(0, 100, 5).setValue(this.plugin.settings.lightness).onChange(async (val) => {
        this.plugin.settings.lightness = val;
        await this.plugin.saveSettings();
        if (this.applyTimer !== null)
          window.clearTimeout(this.applyTimer);
        this.applyTimer = window.setTimeout(() => {
          void this.plugin.regenerateAllColors();
        }, 200);
      }));
    }
    new import_obsidian2.Setting(el).setName("Color mode").setDesc("Determines which tag wins when a note has multiple tags.").addDropdown((d) => d.addOption("primary", "Primary tag \u2014 first tag in the note wins").addOption("priority", "Priority tag \u2014 user-defined priority order").addOption("multi", "Multi-tag \u2014 falls back to primary (graph view limitation)").setValue(this.plugin.settings.colorMode).onChange(async (val) => {
      this.plugin.settings.colorMode = val;
      await this.plugin.saveSettings();
      await this.plugin.applyCurrentColors();
      this.display();
    }));
    if (this.plugin.settings.colorMode === "priority") {
      new import_obsidian2.Setting(el).setName("Priority tag order").setDesc("Comma-separated tags, highest priority first.  The color of the first matching tag is used.").addTextArea((ta) => {
        ta.setPlaceholder("#project, #client, #meeting").setValue(this.plugin.settings.priorityTags.join(", "));
        ta.inputEl.rows = 3;
        ta.onChange(async (val) => {
          this.plugin.settings.priorityTags = val.split(",").map((s) => s.trim().toLowerCase()).filter((s) => s.length > 0).map((s) => s.startsWith("#") ? s : `#${s}`);
          await this.plugin.saveSettings();
          this.scheduleApply();
        });
      });
    }
    new import_obsidian2.Setting(el).setName("Subtag mode").setDesc("How to color hierarchical tags like #project/alpha.").addDropdown((d) => d.addOption("separate", "Separate \u2014 each subtag gets its own color").addOption("inherit", "Parent inheritance \u2014 subtags inherit parent color with lightness variation").setValue(this.plugin.settings.subtagMode).onChange(async (val) => {
      this.plugin.settings.subtagMode = val;
      await this.plugin.saveSettings();
      await this.plugin.regenerateAllColors();
    }));
    new import_obsidian2.Setting(el).setName("Smart tag blending").setHeading();
    new import_obsidian2.Setting(el).setName("Enable smart blending").setDesc("Each note gets its own color blended from all its tags: primary tag color, subtly shifted toward secondary tags, with fine lightness variation per unique tag combo. Notes with identical tag sets get identical colors.").addToggle((t) => t.setValue(this.plugin.settings.blendTagsEnabled).onChange(async (val) => {
      this.plugin.settings.blendTagsEnabled = val;
      await this.plugin.saveSettings();
      await this.plugin.applyCurrentColors();
      this.display();
    }));
    if (this.plugin.settings.blendTagsEnabled) {
      new import_obsidian2.Setting(el).setName("Monochrome mode").setDesc("Force every note to a shade of a single chosen color. Different tag combos still get distinct lightness/saturation variations, but the hue stays fixed.").addToggle((t) => t.setValue(this.plugin.settings.blendMonochromeEnabled).onChange(async (val) => {
        this.plugin.settings.blendMonochromeEnabled = val;
        await this.plugin.saveSettings();
        await this.plugin.applyCurrentColors();
      }));
      new import_obsidian2.Setting(el).setName("Monochrome base color").setDesc("Base hue used when monochrome mode is on.").then((s) => {
        const input = s.controlEl.createEl("input");
        input.type = "color";
        input.value = this.plugin.settings.blendMonochromeHue;
        input.addClass("atgc-color-swatch");
        input.addEventListener("input", async () => {
          this.plugin.settings.blendMonochromeHue = input.value;
          await this.plugin.saveSettings();
          if (this.plugin.settings.blendMonochromeEnabled) {
            await this.plugin.applyCurrentColors();
          }
        });
      });
    }
    new import_obsidian2.Setting(el).setName("Heat coloring by connections").setHeading();
    new import_obsidian2.Setting(el).setName("Enable heat coloring").setDesc("Color nodes from cold (few links) to hot (many links). Heat colors are placed first in the graph groups, so they override tag colors.").addToggle((t) => t.setValue(this.plugin.settings.heatColoringEnabled).onChange(async (val) => {
      this.plugin.settings.heatColoringEnabled = val;
      await this.plugin.saveSettings();
      await this.plugin.applyCurrentColors();
      this.display();
    }));
    if (this.plugin.settings.heatColoringEnabled) {
      new import_obsidian2.Setting(el).setName("Cold color").setDesc("Color for nodes with the fewest connections.").then((s) => {
        const input = s.controlEl.createEl("input");
        input.type = "color";
        input.value = this.plugin.settings.heatColdColor;
        input.addClass("atgc-color-swatch");
        input.addEventListener("input", async () => {
          this.plugin.settings.heatColdColor = input.value;
          await this.plugin.saveSettings();
          await this.plugin.applyCurrentColors();
        });
      });
      new import_obsidian2.Setting(el).setName("Hot color").setDesc("Color for nodes with the most connections.").then((s) => {
        const input = s.controlEl.createEl("input");
        input.type = "color";
        input.value = this.plugin.settings.heatHotColor;
        input.addClass("atgc-color-swatch");
        input.addEventListener("input", async () => {
          this.plugin.settings.heatHotColor = input.value;
          await this.plugin.saveSettings();
          await this.plugin.applyCurrentColors();
        });
      });
    }
  }
  // ── Display ───────────────────────────────────────────────
  renderDisplay(el) {
    new import_obsidian2.Setting(el).setName("Display").setHeading();
    new import_obsidian2.Setting(el).setName("Show legend in graph view").setDesc("Overlay a color legend on every graph view pane.").addToggle((t) => t.setValue(this.plugin.settings.showLegend).onChange(async (val) => {
      this.plugin.settings.showLegend = val;
      await this.plugin.saveSettings();
      this.plugin.updateLegends();
    }));
    new import_obsidian2.Setting(el).setName("Legend visible").setDesc("Quickly hide/show the legend without disabling it.").addToggle((t) => t.setValue(this.plugin.settings.legendVisible).onChange(async (val) => {
      this.plugin.settings.legendVisible = val;
      await this.plugin.saveSettings();
      this.plugin.updateLegends();
    }));
  }
  // ── Per-tag colour list ───────────────────────────────────
  renderTagList(el) {
    new import_obsidian2.Setting(el).setName("Tag colors").setHeading();
    const lastScan = this.plugin.settings.lastScanTime;
    if (lastScan > 0) {
      el.createEl("p", {
        cls: "atgc-last-scan",
        text: `Last scan: ${new Date(lastScan).toLocaleString()}`
      });
    }
    const tagCount = Object.keys(this.plugin.settings.tagColors).length;
    el.createEl("p", {
      cls: "atgc-last-scan",
      text: `${tagCount} tag${tagCount !== 1 ? "s" : ""} tracked.`
    });
    const searchWrap = el.createDiv({ cls: "atgc-search-container" });
    const searchEl = searchWrap.createEl("input", { cls: "atgc-search-input" });
    searchEl.type = "text";
    searchEl.placeholder = "Search tags\u2026";
    const listWrap = el.createDiv({ cls: "atgc-tag-list-container" });
    this.populateTagList(listWrap, "");
    searchEl.addEventListener("input", () => {
      this.populateTagList(listWrap, searchEl.value);
    });
  }
  populateTagList(container, filter) {
    var _c, _d;
    container.empty();
    const { tagColors, lockedColors } = this.plugin.settings;
    const counts = this.plugin.tagNoteCounts;
    const filterL = filter.toLowerCase();
    const entries = Object.entries(tagColors).filter(([tag]) => !filterL || tag.toLowerCase().includes(filterL)).sort(([, , ca = ((_a) => (_a = counts.get("")) != null ? _a : 0)()], [, , cb = ((_b) => (_b = counts.get("")) != null ? _b : 0)()]) => {
      var _a2, _b2;
      return ((_a2 = counts.get("")) != null ? _a2 : 0) - ((_b2 = counts.get("")) != null ? _b2 : 0);
    }).sort(([a], [b]) => {
      var _a, _b;
      return ((_a = counts.get(b)) != null ? _a : 0) - ((_b = counts.get(a)) != null ? _b : 0);
    });
    if (entries.length === 0) {
      container.createEl("p", {
        cls: "atgc-no-tags",
        text: filter ? "No tags match your search." : 'No tags found. Click "Scan vault now" above.'
      });
      return;
    }
    for (const [tag, color] of entries) {
      const row = container.createDiv({ cls: "atgc-tag-row" });
      const displayColor = this.plugin.graphIntegration.getDisplayColorForTag(tag, color);
      const dot = row.createSpan({ cls: "atgc-tag-dot" });
      dot.style.backgroundColor = displayColor;
      row.createSpan({ cls: "atgc-tag-name", text: tag });
      row.createSpan({
        cls: "atgc-tag-count",
        text: `${(_c = counts.get(tag)) != null ? _c : 0} notes`
      });
      const picker = row.createEl("input", { cls: "atgc-color-picker" });
      picker.type = "color";
      picker.value = displayColor;
      picker.addEventListener("input", async () => {
        const newBase = picker.value;
        this.plugin.settings.tagColors[tag] = newBase;
        const newDisplay = this.plugin.graphIntegration.getDisplayColorForTag(tag, newBase);
        dot.style.backgroundColor = newDisplay;
        await this.plugin.saveSettings();
        await this.plugin.applyCurrentColors();
      });
      const locked = (_d = lockedColors[tag]) != null ? _d : false;
      const lockBtn = row.createEl("button", { cls: "atgc-lock-btn" });
      lockBtn.textContent = locked ? "\u{1F512}" : "\u{1F513}";
      lockBtn.title = locked ? "Locked \u2013 click to allow auto-regeneration" : "Unlocked \u2013 click to lock this colour";
      lockBtn.addEventListener("click", async () => {
        var _a;
        const nowLocked = !((_a = this.plugin.settings.lockedColors[tag]) != null ? _a : false);
        this.plugin.settings.lockedColors[tag] = nowLocked;
        lockBtn.textContent = nowLocked ? "\u{1F512}" : "\u{1F513}";
        lockBtn.title = nowLocked ? "Locked \u2013 click to allow auto-regeneration" : "Unlocked \u2013 click to lock this colour";
        await this.plugin.saveSettings();
      });
      const resetBtn = row.createEl("button", { cls: "atgc-reset-btn" });
      resetBtn.textContent = "\u21BA";
      resetBtn.title = "Reset this tag\u2019s color";
      resetBtn.addEventListener("click", async () => {
        delete this.plugin.settings.tagColors[tag];
        delete this.plugin.settings.lockedColors[tag];
        await this.plugin.saveSettings();
        await this.plugin.fullScanAndApply();
        this.display();
      });
    }
  }
};

// src/main.ts
var AutoTagGraphColorsPlugin = class extends import_obsidian3.Plugin {
  constructor() {
    super(...arguments);
    this.tagNoteCounts = /* @__PURE__ */ new Map();
    this.scanDebounce = null;
    this.SCAN_DELAY = 2e3;
  }
  // ms
  // ── Plugin lifecycle ──────────────────────────────────────
  async onload() {
    await this.loadSettings();
    this.tagScanner = new TagScanner(this.app);
    this.colorManager = new ColorManager(this.settings);
    this.graphIntegration = new GraphIntegration(this.app, this.settings);
    this.addSettingTab(new AutoTagGraphSettingTab(this.app, this));
    this.addCommand({
      id: "atgc-scan-vault",
      name: "Scan vault and apply tag colors",
      callback: () => {
        void this.fullScanAndApply();
      }
    });
    this.addCommand({
      id: "atgc-regenerate-colors",
      name: "Regenerate all tag colors",
      callback: () => {
        void this.regenerateAllColors();
      }
    });
    this.addCommand({
      id: "atgc-toggle-legend",
      name: "Toggle tag color legend",
      callback: () => {
        void this.toggleLegend();
      }
    });
    this.app.workspace.onLayoutReady(() => {
      void this.initialize();
    });
  }
  onunload() {
    var _a, _b, _c;
    if (this.scanDebounce) {
      window.clearTimeout(this.scanDebounce);
      this.scanDebounce = null;
    }
    void ((_b = this.graphIntegration) == null ? void 0 : _b.clearManagedGroups((_a = this.settings.managedQueries) != null ? _a : []));
    (_c = this.graphIntegration) == null ? void 0 : _c.removeAllLegends();
  }
  // ── Initialisation ────────────────────────────────────────
  async initialize() {
    this.registerEvent(
      this.app.metadataCache.on("resolved", () => {
        if (this.settings.enabled && this.settings.autoRefresh) {
          this.scheduleScan();
        }
      })
    );
    this.registerEvent(
      this.app.metadataCache.on("changed", (_file) => {
        if (this.settings.enabled && this.settings.autoRefresh) {
          this.scheduleScan();
        }
      })
    );
    this.registerEvent(
      this.app.vault.on("delete", (abstractFile) => {
        if (abstractFile instanceof import_obsidian3.TFile && abstractFile.extension === "md" && this.settings.enabled && this.settings.autoRefresh) {
          this.scheduleScan();
        }
      })
    );
    this.registerEvent(
      this.app.workspace.on("layout-change", () => {
        if (this.settings.showLegend) {
          this.updateLegends();
        }
      })
    );
    if (this.settings.enabled) {
      await this.fullScanAndApply();
    }
  }
  // ── Debounced scan scheduling ─────────────────────────────
  scheduleScan() {
    if (this.scanDebounce)
      window.clearTimeout(this.scanDebounce);
    this.scanDebounce = window.setTimeout(() => {
      this.scanDebounce = null;
      void this.fullScanAndApply();
    }, this.SCAN_DELAY);
  }
  // ── Core operations ───────────────────────────────────────
  /**
   * Full vault scan → assign colours to new tags → write graph.json.
   * Safe to call multiple times; locked colours are never changed.
   */
  async fullScanAndApply() {
    if (!this.settings.enabled)
      return;
    const counts = this.tagScanner.scanAllTags();
    this.tagNoteCounts = counts;
    const eligible = this.filterEligible(counts);
    let changed = false;
    for (const tag of eligible) {
      if (this.settings.lockedColors[tag])
        continue;
      if (!this.settings.tagColors[tag]) {
        if (this.settings.subtagMode === "inherit") {
          const parentKey = this.colorManager.getParentTag(tag);
          if (parentKey) {
            const parentWithHash = parentKey.startsWith("#") ? parentKey : `#${parentKey}`;
            const parentColor = this.settings.tagColors[parentWithHash];
            if (parentColor) {
              const depth = this.colorManager.getTagDepth(tag);
              this.settings.tagColors[tag] = this.colorManager.generateChildColor(
                parentColor,
                depth
              );
              changed = true;
              continue;
            }
          }
        }
        const existing = Object.values(this.settings.tagColors);
        this.settings.tagColors[tag] = this.colorManager.generateColorForTag(tag, existing);
        changed = true;
      }
    }
    if (changed)
      await this.saveSettings();
    await this.applyCurrentColors();
    this.settings.lastScanTime = Date.now();
    await this.saveSettings();
  }
  /** Apply the current tagColors map to the graph without rescanning. */
  async applyCurrentColors() {
    const fileTags = this.settings.blendTagsEnabled ? this.tagScanner.getAllFileTags() : void 0;
    const managedQueries = await this.graphIntegration.applyColors(
      this.settings.tagColors,
      this.settings.priorityTags,
      this.settings.colorMode,
      this.settings.managedQueries,
      fileTags
    );
    this.settings.managedQueries = managedQueries;
    await this.saveSettings();
    if (this.settings.showLegend) {
      this.updateLegends();
    }
  }
  filterEligible(counts) {
    return Array.from(counts.entries()).filter(([tag, count]) => {
      if (this.settings.excludedTags.includes(tag))
        return false;
      if (this.settings.ignoreSingleUseTags && count <= 1)
        return false;
      return true;
    }).map(([tag]) => tag);
  }
  // ── Public commands (also called from settings tab) ───────
  async regenerateAllColors() {
    for (const tag of Object.keys(this.settings.tagColors)) {
      if (!this.settings.lockedColors[tag]) {
        delete this.settings.tagColors[tag];
      }
    }
    await this.saveSettings();
    await this.fullScanAndApply();
    new import_obsidian3.Notice("Auto Tag Graph Colors: colors regenerated.");
  }
  async toggleLegend() {
    this.settings.legendVisible = !this.settings.legendVisible;
    await this.saveSettings();
    this.updateLegends();
  }
  updateLegends() {
    this.app.workspace.getLeavesOfType("graph").forEach((leaf) => {
      this.graphIntegration.updateLegend(
        leaf,
        this.settings.tagColors,
        this.tagNoteCounts,
        async (tag, newColor) => {
          this.settings.tagColors[tag] = newColor;
          await this.saveSettings();
          await this.applyCurrentColors();
        },
        async (visible) => {
          this.settings.legendVisible = visible;
          await this.saveSettings();
        }
      );
    });
  }
  // ── Settings persistence ──────────────────────────────────
  async loadSettings() {
    this.settings = Object.assign(
      {},
      DEFAULT_SETTINGS,
      await this.loadData()
    );
  }
  async saveSettings() {
    var _a, _b;
    await this.saveData(this.settings);
    (_a = this.colorManager) == null ? void 0 : _a.updateSettings(this.settings);
    (_b = this.graphIntegration) == null ? void 0 : _b.updateSettings(this.settings);
  }
};

/* nosourcemap */